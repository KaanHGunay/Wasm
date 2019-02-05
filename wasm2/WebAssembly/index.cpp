#include <emscripten.h>
#include <stdio.h>



#ifdef __cplusplus
extern "C" {
    #endif

    EMSCRIPTEN_KEEPALIVE
    int add(int a, int b) {
        return a + b;
    }

    EMSCRIPTEN_KEEPALIVE
    int sayHello() {
        printf("Hello");
        return 0;
    }
    
    #ifdef __cplusplus
}
#endif

// emcc index.cpp -o index.js -O3 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap']" -s "EXPORTED_FUNCTIONS=['_sayHello', '_add']"