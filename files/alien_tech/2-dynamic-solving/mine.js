// my code for instantiating a wasm module via js

const memory = new WebAssembly.Memory({ initial: 256, maximum: 256 });

importObj = {
	wasi_snapshot_preview1: {
		// fd_write: function() {}, // it's not actually used so we can just fake it out
		fd_write: console.log
	},
	env: {
		emscripten_resize_heap: function() {},
		emscripten_memcpy_big: function() {},
		__handle_stack_overflow: function() {},
		setTempRet0: function() {},
		memory: memory,
        table: new WebAssembly.Table({ initial: 6, maximum: 100, element: 'anyfunc' })
	}
}

console.log("attempting to load the wasm module")

WebAssembly.instantiateStreaming(fetch('alien_tech.wasm'), importObj)
.then(obj => {
  // Call an exported function:
  // obj.instance.exports.exported_func();

  // or access the buffer contents of an exported memory:
  // var i32 = new Uint32Array(obj.instance.exports.memory.buffer);

  // or access the elements of an exported table:
  var exports_list = obj.instance.exports;
  var mainfunc = exports_list.main;

  console.log('running main')

  var args = new Array();
  args.push('foo'); // arg1
  args.push('bar'); // arg2

  // the following calls main directly, which is not what we want
  // (we want to setup a proper argv on the stack)

  // var result = mainfunc(4,5246528);

  // it is not clear to me how to do so. the following is code from emscripten.
  // use given.js for now.

  // var argc = args.length+1;
  // var argv = stackAlloc((argc + 1) * 4);
  // HEAP32[argv >> 2] = allocateUTF8OnStack(thisProgram);
  // for (var i = 1; i < argc; i++) {
  //   HEAP32[(argv >> 2) + i] = allocateUTF8OnStack(args[i - 1]);
  // }
  // HEAP32[(argv >> 2) + argc] = 0;

  console.log("retval of main: ")
  console.log(result)
})

