---
layout: post
title: "boilerctf: old-oaken-bucket"
date: 2018-11-05 00:02:00 -0500
published: true
---

Simple reversing challenge from an internal Purdue ctf that i \*ahem\*'d my
way into. [Download link](https://www.dropbox.com/s/d1v6a5708cwzzs5/old-oaken-bucket?dl=0).

The interesting block is pretty clear (it's the longest and it's in main):

<img width='100%' src='/images/old-oaken-bucket.png'>

Reversing it by hand looks tedious. `cdq` is just "convert doubleword to
quadword" with a sign extend.

Throwing it into IDA comes out pretty gross:
```
__int64 __fastcall main(int a1, char **a2, char **a3)
{
  size_t v3; // rbx@4
  int i; // [sp+1Ch] [bp-14h]@7

  if ( a1 != 2 )
  {
    printf("Usage: %s <flag>\n", *a2, a3, a2);
    exit(0);
  }
  v3 = strlen(a2[1]);
  if ( v3 != strlen(&s) )
  {
    puts("OH NOES IU WON!");
    exit(0);
  }
  for ( i = 0; i < strlen(a2[1]); ++i )
  {
    if ( (unsigned __int8)(*(&s + i) ^ byte_400808[(unsigned __int64)(unsigned __int8)byte_400810[(signed __int64)(signed int)(((((unsigned int)((unsigned __int64)i >> 32) >> 29) + (_BYTE)i) & 7) - ((unsigned int)((unsigned __int64)i >> 32) >> 29))]]) != a2[1][i] )
    {
      puts("OH NOES IU WON!");
      exit(0);
    }
  }
  puts("BOILER UP!");
  return 0LL;
}
```

We know that at some point, the binary's going to do a byte compare
(second-to-last instruction in the basic block above). 

The binary's stripped so GDB doesn't know where main is. We use our
standard hack to set a breakpoint on the entry point: `b * 0, r, b *$pc, d
1`. That runs us through the dynamic linker which sucks to step through, so
I pull the address of that block out of Binja and just break on that
instead.

We can tell (by looking @ disassembly in Binja) that the program expects a
32 byte-long string as the first argument.

Stepping through that block, we notice something useful: the last
instruction before the jump compares the input string untouched against the
now-deobfuscated flag. However, it'll probably fail the check (as our input
is wrong) and quit us out. So we can do the following:

1. Run GDB to that breakpoint
2. Write down the next character of the flag from RDX
3. Restart the program, adding the character from the flag we just learned.

This works, but it's not *fast*. We can do better.

1. Set a breakpoint on the `cmp` instruction instead.
1. Take the opposite path of the fork every time we get to the jump (ie
`set $rip=0x4006d6`.
2. `continue` back to the `cmp` instruction again, and read off RDX (peda
or `display/c $rdx`.

This works because that basic block doesn't modify the state in any weird
way. Pretty much just a coincidence.

But, that's not fast enough. We can do better.

GDB doesn't have command separation built in (it honestly leaves a lot to
be desired from the "works like a nice shell" standpoint). We can [hack it
in with Python](https://stackoverflow.com/a/51804606/1234621).

Now, we just need to set a breakpoint on the `cmp and:

1. `cmds set $rip=0x4006d6 ; c`
2. Mash up+enter.

```
(gdb) b * 0x4006be
Breakpoint 1 at 0x4006be
(gdb) r aoeuaoeuaoeuaoeuaoeuaoeuaoeuaoeu
Starting program: /root/old-oaken-bucket aoeuaoeuaoeuaoeuaoeuaoeuaoeuaoeu

Breakpoint 1, 0x00000000004006be in ?? ()
(gdb) display/c $rdx
1: /c $rdx = 66 'B'
(gdb) cmds set $rip=0x4006d6 ; c
Continuing.

Breakpoint 1, 0x00000000004006be in ?? ()
1: /c $rdx = 67 'C'
(gdb) cmds set $rip=0x4006d6 ; c
Continuing.

Breakpoint 1, 0x00000000004006be in ?? ()
1: /c $rdx = 84 'T'
(gdb) cmds set $rip=0x4006d6 ; c
Continuing.

Breakpoint 1, 0x00000000004006be in ?? ()
1: /c $rdx = 70 'F'
(gdb) cmds set $rip=0x4006d6 ; c
```

Nice and quick.

Next up: emulate it with unicorn and write a tiny python script to do the
same thing.
