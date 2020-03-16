I tried two approaches to generating C, both from wabt.

wasm-decompile appeared to generate javascript, which was not what I
wanted.

`~/wabt/build/wasm-decompile ../given/alien_tech.wasm > from-wasm-decompile.js`

The approach I ended up using was `wasm2c`, which created an x86 object
file that I could then look at in ghidra.
```
~/wabt/build/wasm2c ../alien_tech.wasm -o source_from_wasm2c.c
gcc -c  -o bin_from_wasm2c source_from_wasm2c.c -I wasm2c
```

