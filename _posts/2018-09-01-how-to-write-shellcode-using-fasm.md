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
format binary
use32 ; 32b
	push 0xb7f83a24 ; ptr to shstr
	push 0xb7e63190 ; addr of system
	jmp  DWORD [esp] ; addr of system
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

