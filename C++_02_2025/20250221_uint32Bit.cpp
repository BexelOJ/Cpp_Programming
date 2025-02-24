#include <iostream>
#include <cstdio>
#include <cstdint>

using namespace std;

int main()
{
uint64_t a = 0xffff1234;
uint32_t b = 0xffff1234;
uint32_t c = 078;
//uint32_t d = 0d32;
uint32_t e = 0b1111000011110001;

//printf("%d\n",a);
printf("%lb\n",a);  // binary
printf("%b\n",b);

printf("%lo\n",a);   // oct
printf("%o\n",b);

printf("%ld\n",a);   // dec
printf("%d\n",b);

printf("%lX\n",a);  // hex
printf("%X\n",b);

printf("%o\n",c);  // c
printf("%o\n",c);

printf("%ld\n",a);  // d
printf("%d\n",b);

printf("%lb\n",a);  // e
printf("%b\n",b);

//printf("%X\n",a);
return 0;
}



