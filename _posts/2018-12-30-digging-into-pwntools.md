---
layout: post
title: "Digging into pwntools"
date: 2018-12-30 14:40:00 -0900
published: true
---

I'm digging around into how pwntools is packaged. It looks really nicely organized and commented.

#### Get the path of a python modules

```python
import pwn
print(pwn.__file__)
```

The `pwn` module is just a top-level with nice naming — `pwnlib` actually contains all the functionality.

`dynelf.py` is really interesting — it lets you resolve any symbol in a binary given a function `leak(arbitrary_address)`.