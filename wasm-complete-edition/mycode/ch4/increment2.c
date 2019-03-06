// emcc command: 
// emcc increment2.c \
// -o increment2.js \
// -s INVOKE_RUN=0 \
// -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']"

#include <stdio.h>
#include <emscripten.h>
EMSCRIPTEN_KEEPALIVE int increment(int num) {
    num++;
    printf("%d\n", num);
    return 0;
}