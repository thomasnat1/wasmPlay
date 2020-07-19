#include <stdio.h>
#include <emscripten.h>

EM_JS(void, jsFunction, (int n), {
    console.log("call from EM_JS: " + n);
} );

int main() {
    printf("wasm ready in main\n");

    //call JS function eval 
    emscripten_run_script("console.log('pie called through emscripten')");

    emscripten_async_run_script("console.log('hello from C async style!')", 2000);

    int jsVal = emscripten_run_script_int("getNum()");

    char * jsValStr = emscripten_run_script_string("getStr()");

    printf("Val is %d\n", jsVal);
    printf("Val is %s\n", jsValStr);

    jsFunction(33);
    
    return 42;
}