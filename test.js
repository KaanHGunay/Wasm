

function is_prime_js(number) {
    control_number = number;
    a = 2;
    while(control_number > a){
        if(number % a != 0){
            control_number = number / a;
            a++;
        } else {
            return false;
        }
    }
    return true;
}

function find_prime_numbers_js(number) {
    start_point = 2;
    found_primes = 0;
    while(found_primes <= number){
        if(is_prime_js(start_point)){
            found_primes++;
        }
        start_point++;
    }
}

function measure_js_time(number) {
    var t0 = performance.now();
    find_prime_numbers_js(number);
    var t1 = performance.now();
    console.log((t1 - t0) + " milliseconds.");
}

/*
find_prime_numbers_c = Module.cwrap('find_prime_numbers', 'null', ['number']);
function measure_c_time(number) {
    var t0 = performance.now();
    find_prime_numbers_c(number);
    var t1 = performance.now();
    console.log((t1 - t0) + " milliseconds.");
}
*/