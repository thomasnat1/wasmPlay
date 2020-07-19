#include <stdio.h>
#include <string.h> 

int main() {
    printf("wasm ready in main\n");
    return 42;
}

int getNum(){
    return 323;
}

int getDouble(int num){
    return num * 2;
}

char * greet(char * name){
    char * greeting = "Hey fucking ";
    strcat(greeting, name);
    return greeting;
}