---
layout: post
title: "canonical pwntools script"
date: 2018-09-30 05:52:00 -0500
published: true
---

I constantly find myself going back through old exploits for scripts, so
I'm going to try keeping up my "current favorite pwn scripts" here.

```
from pwn import *

p = process("./path")
print util.proc.pidof(p) # useful with a pause() to connect gdb if pwnlib's gdb isn't working for whatever reason

p.send("banana")
p.recv() # p sure this is capped at 4096 bytes or something
p.sendline("this sends a newline after")

p.interactive() # look we got a shell
```

```
# alternative to the above, keeps the pipe open after sending the exploit
# so as to enable you to actually use the shell.
cat <(python solve.py) - | ./binary
```
