// Compile command: emcc increment.c -o increment.js -s EXPORTED_FUNCTIONS="['_increment']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']"
#include <stdio.h>
int increment(int num) {
    num++;
    printf("%d\n", num);
    return 0;
}