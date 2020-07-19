// compile command: emcc file.c -o file.js 
#include <stdio.h>
int main(){
    // Open myFile.txt for reading
    FILE *fp = fopen("myFile.txt", "r");
    
    // Until we reach the end of the file (EOF), output the next character
    char c;
    while((c = fgetc(fp)) != EOF)
        printf("%c", c);
    
    // Close the file
    fclose(fp);
    // Flush stdout; otherwise, we get a warning in the developer console that
    // looks like this: "stdio streams had content in them that was not flushed"
    printf("\n");
    return 0;
}