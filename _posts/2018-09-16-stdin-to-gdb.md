---
layout: post
title: "passing std to a process in gdb"
date: 2018-09-16 17:07:00 -0500
published: true
---

[via][1]

```
# run it in a subshell and get the stdout fd
r < <(python -c "print '\x41'*36" | binary)
```

```
# bash command substitution into how gdb does stdin
r <<< $(python -c "print '\x41'*36")
```

[1]: https://dustri.org/b/feed-binary-stdin-from-inside-gdb.html 
