---
layout: post
title: "WASM Reversing (b01lerctf 2020 alientech web 300)"
date: 2020-03-15 20:44:14 -0700
published: true
---

We're given a WASM binary and a webserver asking for a username and
password.

<img width='100%' src='/ctf-blog/images/alien-tech/0.png'>

1. I used wabt to compile the wasm to C.
2. I compiled the C to an x86 object file (since it was looking for imports
and I didn't care about them.
3. I threw the object file in Ghidra and started copying out chunks of
relevant decompiled C into a text editor.

This was a lot easier to read than any of the intermediate stages.

I also set up the required HTML and JS to run WebAssembly. However, I got
the arg passing wrong, so I kept crashing my tab because argv held illegal
addresses, which was super frustrating. Eventually they gave us an
emscripten.js that had been generated by the emscripten compiler, which
enabled me to pass args correctly.

I spent most of the weekend reading / marking up the C. Eventually, I
learned:

* Function #8 xor's a region of memory to give you `N Gonzalez`. This is
clearly a username, which suggests you should feed it to the HTTP Basic Auth.

### The intended solve

* Submit `N Gonzalez` as the username and notice that the web server now
gives you back a "Progress" header that is an int.
* Brute force the password using the Progress header. If the value goes up,
you're on the right track.

### What I did

* 10 hours of reversing C that had been generated from x86 that had been
generated from C that had been generated from wasm.

I learned that this block was strlen, for example:

```c
// takes a pointer to one of the arguments
// only used in f9 afaict
// called on both arguments
// does no stores, meaning it simply returns some value

// input: banana, output: 6
// LENGTH CHECK
ulong _getLength(uint param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_1c;
  uint local_14;
  uint local_10;

  uVar1 = param_1;
  if ((param_1 & 3) == 0) {
    do {
      local_10 = uVar1;
      local_14 = local_10;
      uVar2 = load(local_10);
      uVar1 = local_10 + 4;
    } while ((uVar2 + 0xfefefeff & (uVar2 ^ 0xffffffff) & 0x80808080) == 0);
    if ((uVar2 & 0xff) == 0) {
      local_1c = local_10 - param_1;
      return local_1c;
    }
    do {
      iVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)(local_14 + 1));
      local_14 = local_14 + 1;
      local_10 = local_14;
    } while (iVar3 != 0);
  }
  else {
    iVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)param_1);
    local_10 = param_1;
    if (iVar3 == 0) {
      local_1c = 0;
      return local_1c;
    }
    do {
      local_10 = local_10 + 1;
      uVar1 = local_10;
      if ((local_10 & 3) == 0) goto LAB_00018993;
      iVar3 = load8_u(local_10);
    } while (iVar3 != 0);
  }
  local_1c = local_10 - param_1;
  return local_1c;
}
```

`main` was pretty reasonable, and I could guess which function (9) did the
interesting work. However, it was pretty clearly an unreasonable amount to
reverse.