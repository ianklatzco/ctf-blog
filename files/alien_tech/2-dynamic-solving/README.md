`python -m http.server` and open
[http://localhost:8000/given.html](http://localhost:8000/given.html) in
browser.

given.html does arg passing correctly, so you can modify args in
`alien_tech.js` and see how they differ for the binary.

mine.html does not, and does not correctly instantiate all the imports
either. that's what i used at first, before they gave us the emscripten
output.

`xor.py` is just the script I used to recover N Gonzalez from the binary. I
pulled the values out of the .wasm file directly (using the .wat to tell me
where they started).
