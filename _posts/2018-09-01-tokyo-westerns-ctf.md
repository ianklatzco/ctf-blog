---
layout: post
title: "Tokyo Westerns CTF: load"
date: 2018-09-01 14:01:00 -0500
published: true
---

## Load
At first glance, it looks like it's nontrivial to locate `main()` in a
stripped ELF.

Via [this SO question][0].

`__libc_start_main` has the following prototype:

```
int __libc_start_main(int (*main) (int, char**, char**), 
                      int argc, 
                      char *__unbounded *__unbounded ubp_av, 
                      void (*init) (void), 
                      void (*fini) (void), 
                      void (*rtld_fini) (void), 
                      void (*__unbounded stack_end));
```

So, we can look at the top address of the stack in order to get a pointer
to main, set a breakpoint on it, and `continue` till we get there.

The entry point of the binary is `0x400720` (via `info file`).
This is distinct from the address of `main` — it corresponds to `_start` in
tools like Binja. (can also be found with `readelf -h ./load | grep Entry`)

[x64 Linux calling convention][1] is these registers for args `RDI, RSI, RDX,
RCX, R8, R9, XMM0–7`.
So, the address of `main` on my local machine on first run is
`0x7ffff7ffe168`. Setting that as a breakpoint and continuing doesn't work.

So, I pull the address of main out of Binja.

I then go reverse the file, annotating it.

Looks like a -1 for the size causes a crash, or at least, a silent exit w/o
a successful file read.

The read appears to read into a stack-allocated variable that doesn't look
very big. I'm guessing that if I read a particular file (maybe something in
/proc that I control, offset to wherever in the binary) then I'll be able to overwrite the return address
with that of libc or something.

`__printf_chk` should still be usable, so I bet I can get arbitrary read.
But I can't write things to the stack, so that's a pain in the ass.

`/dev/stdin` is a file I control 100%, solving that problem.

I'm not sure if ASLR is on or not, but I'm guessing no. I can probably
check by `cat`ting a file.

I think the proper approach is ROP, by loading the stack with some
addresses. But, I need addresses. I have things in the code section so I
can search for ROP gadgets there.

I'm curious if a shellcode-level execve can do pipes. I think the answer is
yes?

Sebastian pointed me to `reopen`, and "try to open /dev/console or something as fd 1".


Misc other stuff:

 * `__printf_chk` is `printf` with stack checking to prevent `%n`.
 * `/proc/self/mem` gives us arbitrary memory, but we don't actually see the output ever so that's nothing.
 * .got.plt and .plt.got are two separate things. .plt.got has AX, .got.plt has WA. `readelf -S` for sections.


[0]: https://stackoverflow.com/questions/9885545/how-to-find-the-main-functions-entry-point-of-elf-executable-file-without-any-s
[1]: https://en.wikipedia.org/wiki/X86_calling_conventions#List_of_x86_calling_conventions
