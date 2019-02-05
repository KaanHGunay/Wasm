Module.onRuntimeInitialized = _ => {
    //const add = Module.cwrap('add', 'number', ['number', 'number']);
    //const sayHello = Module.cwrap('sayHello', 'null', []);
    //console.log(add(2, 3));
    //sayHello();
}

const add = Module.cwrap('add', 'number', ['number', 'number']);
const sayHello = Module.cwrap('sayHello', null, null);

function add_js(a,b) {
    return a + b;
}

function measure_js_add_time(a, b) {
    var t0 = performance.now();
    add_js(a, b);
    var t1 = performance.now();
    console.log((t1 - t0) + " milliseconds.");
}

function measure_c_add_time(a, b) {
    var t0 = performance.now();
    add(a, b);
    var t1 = performance.now();
    console.log((t1 - t0) + " milliseconds.");
}