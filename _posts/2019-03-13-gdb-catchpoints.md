---
layout: post
title: "GDB Catchpoints"
date: 2019-03-13 20:12:22 -0500
published: true
---

```
gdb-peda$ help catch
Set catchpoints to catch events.

List of catch subcommands:

catch assert -- Catch failed Ada assertions
catch catch -- Catch an exception
catch exception -- Catch Ada exceptions
catch exec -- Catch calls to exec
catch fork -- Catch calls to fork
catch handlers -- Catch Ada exceptions
catch load -- Catch loads of shared libraries
catch rethrow -- Catch an exception
catch signal -- Catch signals by their names and/or numbers
catch syscall -- Catch system calls by their names
catch throw -- Catch an exception
catch unload -- Catch unloads of shared libraries
catch vfork -- Catch calls to vfork

Type "help catch" followed by catch subcommand name for full documentation.
Type "apropos word" to search for commands related to "word".
Command name abbreviations are allowed if unambiguous.
gdb-peda$
```

So, if you wanted to catch all syscalls, you can `catch syscall`. This will
stop on the entrance and exit of each syscall. Divide by two, and you'll
get the total number of syscalls run by your program.
