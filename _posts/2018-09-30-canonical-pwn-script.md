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

# change logging level. options: debug, critical (high, low)
context.log_level = 'critical'

p = process("./path")
# p = remote('host', 3333)

# useful with a pause() to connect gdb if pwnlib's gdb isn't working for
# whatever reason
# print util.proc.pidof(p) 

p.send("banana")
p.recv() # p sure this is capped at 4096 bytes or something
p.sendline("this sends a newline after")

# p.recvall()

p.interactive() # look we got a shell
```

```
# alternative to the above, keeps the pipe open after sending the exploit
# so as to enable you to actually use the shell.
cat <(python solve.py) - | ./binary
```

```
# int to little endian, in pwn but sometimes i don't have it installed
def p32(x): return struct.pack('<I',x)
```
