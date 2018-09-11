---
layout: post
title: "Locating main() in a stripped binary"
date: 2018-09-10 21:38:00 -0500
published: true
---

I was working on TokyoWesterns 2018 `load` and [this came up (stackoverflow)](https://stackoverflow.com/a/41800308/1234621).

I don't actually know what `strip()` does so let's `man strip`:
```
   GNU strip discards all symbols from object files objfile.  The list of
   object files may include archives.  At least one object file must be
   given.
```

OK, so it removes the symbol that tells us main is main.

So, I can't `b main` in gdb.

(gdb doesn't have command separation but [you can add
it](https://stackoverflow.com/a/51804606/1234621) though it won't work for
this case because the `b * 0` thing is a hack and it throws a python
exception)

I can `b * 0 ; r ; print $rip` to get the address of `_start`, but that's not want I want.

`_start` calls `__libc_start_main()`, which has the following prototype:
```
int __libc_start_main(int (*main) (int, char**, char**), 
                      int argc, 
                      char *__unbounded *__unbounded ubp_av, 
                      void (*init) (void), 
                      void (*fini) (void), 
                      void (*rtld_fini) (void), 
                      void (*__unbounded stack_end));
```

So we can look at the args of `__libc_start_main` to get the address of main.

I need to:
* break on the entrypoint
* find `__libc_start_main` call
* set breakpoint on: last addr saved on stack before `__libc_start_main` call
* continue (until breakpoint for main is hit)

Which is
```
b * 0
r
b * $rip
d 1
r
```

Except, there's a bunch of `dlopen` stuff that I don't expect, since it doesn't
come up in Binja. `objdump -d`'s output matches up with Binja, so there's
something up here involving dynamic loading.

Why doesn't code just start executing at the beginning of `.text`? It's clearly
the entry point of the binary. I'm guessing the linker must be doing some
shenanigans.

I notice that rip points to `0x7ffff7dd7c30`, where static disassembly points
to `0x400720` as the address of `_start`. I can still `x/16i 0x400720` and see
what binja/objdump call \_start/the start of .text, but we're clearly not
there.

Stepped through `dl_main` forever, kinda fruitlessly. `ldd load` gives 
```
	linux-vdso.so.1 =>  (0x00007ffe1a792000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fa016032000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fa0163fc000)
```
 
We can look at the disassembly `objdump -d /lib64/ld-linux-x86-64.so.2 | less`
and it's **long**.

Breaking on `_start` takes me to the first instruction of the dynamic loader,
which is weird to me. I would've expected the first instruction of `.text`
section. But my guess is that the dynamic loader is what's called first, and it
loads everything else. That or gdb just uses it b/c the binary is stripped. So,
the solution is to pull out the entry point manually and then break on that.

And with that, we can see that `rdi` contains `0x400816`, which is main. (had a
brief moment of confusion where I didn't realize that I was x64 and x64 is
register-based arguments).

---

Binja does `_start` identification automatically anyway, which is nice.
