#include <stdio.h>
#include <emscripten.h>

char * str= "my string";

char * getStr(){
    return str;
}

int main() {
    printf("wasm ready in main\n");

    return 1;
}