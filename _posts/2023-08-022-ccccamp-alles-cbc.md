---
layout: post
title: "AES CBC Malleability - ALLES @ CCCCamp 2023"
date: 2023-08-22 19:57:14 +0200
published: false
---

<!--
**[Files](https://github.com/ianklatzco/ctf-blog/tree/master/files/alien_tech)**
-->

I decided it's time to learn more cryptography.

Solved after the event based on  
[this writeup](https://gist.github.com/sshuzl/a81f65f047e578e86625bbfbd18b0ccf).

Two approaches:
- Malleate the sample block until the check passes (since you can flip bits
  in CBC)
- Construct a valid pair of blocks where the second contains a
  breakpoint() statement.


