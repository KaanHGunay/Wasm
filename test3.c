#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
    #endif

    bool is_prime(int number){
        int control_number = number;
        int a = 2;
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

    void find_prime_numbers(int number){
        int start_point = 2;
        int found_primes = 0;
        while(found_primes <= number){
            if(is_prime(start_point)){
                found_primes++;
            }
            start_point++;
        }
    }

    #ifdef __cplusplus
}
#endif


//emcc test3.c -o function.html -s "EXPORTED_FUNCTIONS=['_find_prime_numbers', '_is_prime']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"

//emcc test3.c -o function.html -s "EXPORTED_FUNCTIONS=['_is_prime']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"