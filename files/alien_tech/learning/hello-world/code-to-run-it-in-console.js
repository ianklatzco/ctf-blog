WebAssembly.instantiateStreaming(fetch('hello-world.wasm'),{imports: {} })
.then(obj => {
  // Call an exported function:
  // obj.instance.exports.exported_func();

  // or access the buffer contents of an exported memory:
  // var i32 = new Uint32Array(obj.instance.exports.memory.buffer);

  // or access the elements of an exported table:
  var aoeu = obj.instance.exports;
  console.log(aoeu);
  // console.log(aoeu['helloWorld']());
})