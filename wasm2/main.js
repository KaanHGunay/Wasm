Module.onRuntimeInitialized = _ => {
}

const fib = Module.cwrap('fib', 'number', ['number']);
const add = Module.cwrap('add', 'number', ['number', 'number']);

function t() {
        console.log(fib(7));
}

/*
    emcc func.c -o ball.js -O3 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap']"
*/