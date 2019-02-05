#include <emscripten.h>
#include <stdio.h>

EMSCRIPTEN_KEEPALIVE
int add(int a, int b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
void sayHello() {
    printf("Hello");
}

#ifdef __cplusplus
extern "C" {
    #endif

    #ifdef __cplusplus
}
#endif

// emcc index.cpp -o index.js -O3 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap']" -s "EXPORTED_FUNCTIONS=['_sayHello', '_add']"