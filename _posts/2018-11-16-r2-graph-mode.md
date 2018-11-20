---
layout: post
title: "radare2 basics"
date: 2018-11-05 00:02:00 -0500
published: true
---

*(I wrote this post for our underclassmen, because I kept needing to explain how to get to graph mode in r2 and didn't want to keep repeating myself).*

Radare2 is a vim-like reverse engineering tool. It is free. Your other options are Binary Ninja and IDA, which cost money for anything other than 32 bit binaries. They are substantially easier to learn and use.

Here I'll walk through an alternative way to solve [how2re](http://ctf.sigpwny.com/challenges#how2re) from the one we went over during the meeting.

---

First, install r2 on Linux. `git clone https://github.com/radare/radare2 && cd radare2 && sys/install.sh` (Windows Subsystem for Linux, Ubuntu is recommended, or contact me if you'd like server access.)

Get the challenge file in your Linux environment. You can download it with
`wget http://ctf.sigpwny.com/files/3301150f65f62f644f09b5b4710e2bd4/how2re`.

Open the binary in r2. `r2 how2re`

* r2 likes to print amusing startup messages. For example, I got ` -- How about a nice game of chess?` which is a reference to the movies War Games. You can ignore or disable these.

Press `v` and then `Enter` to enter visual mode. It should look like this:

<img width='100%' src='/ctf-blog/images/r2/0.png'>

Press `p` to rotate "print mode". Press `P` if you want to go back. You should now see disassembly, which is enough to start reverse engineering the binary.

<img width='100%' src='/ctf-blog/images/r2/1.png'>

Press `n` and `N` to navigate back and forth between sections. Stop when you reach `main`.

<img width='100%' src='/ctf-blog/images/r2/2.png'>

Press `df` to define a function at main. (This isn't always necessary).

<img width='100%' src='/ctf-blog/images/r2/3.png'>

Press `V` to enter visual mode. (`q` to go back). Navigate with `hjkl` (vim-style).

<img width='100%' src='/ctf-blog/images/r2/4.png'>

You'll notice that there's a setup block, a block that prints an error messages "Each character in...", and a block that does `scanf`, reading in input.

<img width='100%' src='/ctf-blog/images/r2/5.png'>

You'll also notice that there's a `mov` instruction that moves a byte literal (hardcoded value) into a register). r2 helpfully tells you what this byte literal is in ascii.

If you look at all of the literals, you'll notice a pattern: `flag{...`, which continues for the rest of the binary. You can use this to read off the entire flag, solving the challenge.

**Note**: You can display the help menu at any time by pressing `?` (`Shift+/`). `q` to go back.
