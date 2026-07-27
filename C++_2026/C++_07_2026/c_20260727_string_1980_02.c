#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("Hello World!\n");

    char src[] = "Hello";
    const char* str = "World";
    char dest[20];

    strcpy(dest, src);
    bool comp = strcmp(dest, src);
    int l = strlen(dest);

    printf("src: %s\n",src);
    printf("str: %s\n", str);
    printf("dest: %s\n", dest);
    printf("comp: %d\n", comp);
    printf("l: %d\n", l);

}




