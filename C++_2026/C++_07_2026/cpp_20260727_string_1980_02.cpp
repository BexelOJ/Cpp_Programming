#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    printf("Hello World!\n");

    char src[] = "Hello";
    const char* str = "World";
    char dest[20];

    std::strcpy(dest, src);
    bool comp = std::strcmp(dest, src);
    int l = std::strlen(dest);

    printf("\n%s",src);
    std::cout << src << std::endl;
    std::cout << str << std::endl;
    std::cout << dest << std::endl;
    std::cout << comp << std::endl;
    std::cout << l << std::endl;

}




