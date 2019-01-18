---
layout: post
title: "peda.py reference"
date: 2019-01-18 00:50:00 -0600
published: true
---

A few PEDA commands are undocumented (on the first page of the GitHub repo,
there's more useful help in `help`). Here are my notes.

There are a bunch of useful aliases at the [bottom of the file][2].

### stack n
Prints `n` words off the stack.

### context

Type `context` to re-print what usually prints at a breakpoint (registers, code, stack).

### Built-in exploit code

```
gdb-peda$ help skeleton
Generate python exploit code template
Usage:
    skeleton type [file]
        type = argv: local exploit via argument
        type = env: local exploit via crafted environment (including NULL byte)
        type = stdin: local exploit via stdin
        type = remote: remote exploit via TCP socket
```

### Skip over certain functions (alarm)
```
gdb-peda$ help deactive
Bypass a function by ignoring its execution (eg sleep/alarm)
Usage:
    deactive function
    deactive function del (re-active)
```


[2]: https://github.com/longld/peda/blob/7f673be05db619105bc3e0203aad57844a1665e0/peda.py#L6151