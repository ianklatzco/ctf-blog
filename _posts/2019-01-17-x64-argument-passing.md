---
layout: post
title: "x64 Argument Passing"
date: 2019-01-17 22:56:00 -0600
published: true
---

[via](https://eli.thegreenplace.net/2011/09/06/stack-frame-layout-on-x86-64)

```
According to the ABI, the first 6 integer or pointer arguments to a
function are passed in registers. The first is placed in rdi, the second in
rsi, the third in rdx, and then rcx, r8 and r9. Only the 7th argument and
onwards are passed on the stack.
```
