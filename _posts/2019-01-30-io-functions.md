---
layout: post
title: "IO Functions"
date: 2019-01-30 04:17:22 -0600
published: true
---

Manners of getting input. From memory, maybe more later.

x86, 32 & 64b.

`read from stdin to a buffer`: Will read any character (incl. nulls).

`fgets`: reads up to n-1. terminates on nulls. adds a newline.

`scanf`: varargs. takes a format string specifier, eg `scanf("%9s", mem_loc);`.

`getc in a while() loop`: probably my least favorite.

`mmap()`

`port mapped io`: x86 instructions `in` and `out`

`mmio`