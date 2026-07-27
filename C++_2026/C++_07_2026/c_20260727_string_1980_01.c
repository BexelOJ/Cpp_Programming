#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello";
    char* str = "World";
    char dest[20];

    int len_01 = strlen(src);
    int len_02 = strlen(str);
    int len_03 = strlen(dest);

    strcpy(dest, str);

    printf("src: %s\n",src);
    printf("str: %s\n", str);
    printf("dest: %s\n", dest);

    printf("Length: %d\n",len_01);
    printf("Length: %d\n", len_02);
    printf("Length: %d\n", len_03);

    return 0;
}


