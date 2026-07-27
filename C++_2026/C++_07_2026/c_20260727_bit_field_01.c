#include <stdio.h>
#include <string.h>

struct Flags
{
    unsigned int a : 1;
    unsigned int b : 1;
};

typedef struct Scale
{
    unsigned int x : 1;
    unsigned int y : 1;
}scl;

int main(void)
{
    printf("Hello World\n");

    //char[10] s = "India";
    //printf("%s\n",s);

    struct Flags f;
    scl s;

    f.a = 0;
    f.b = 1;

    s.x = 1;
    s.y = 0;

    printf("%u\n", f.a);
    printf("%u\n", f.b);

    printf("%u\n", s.x);
    printf("%u\n", s.y);

    return 0;
}



