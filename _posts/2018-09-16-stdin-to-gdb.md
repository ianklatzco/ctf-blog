---
layout: post
title: "passing to a process's stdin in gdb"
date: 2018-09-16 17:07:00 -0500
published: true
---

[via][1]

Sometimes you want to pipe things into a process's stdin (to emulate typing
things, for example.)
```
echo "blah" | binary
python -c "print hello" | binary # is another common thing.
```

But what if you want to do that with a process you're starting via gdb?
Gets a little more complicated, but gdb has things built in to do such
things.

```
# run it in a subshell and get the stdout fd
gdb binary
r < <(python -c "print '\x41'*36")
```

```
# bash command substitution into how gdb does stdin
r <<< $(python -c "print '\x41'*36")
# note! this handles nulls weirdly on stdin within gdb. (leakless, fireshellctf)
# the above did not have this issue.
```

[1]: https://dustri.org/b/feed-binary-stdin-from-inside-gdb.html 
