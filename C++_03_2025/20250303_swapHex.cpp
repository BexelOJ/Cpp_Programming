#include <iostream>
#include <cstdint>
#include <cstdio>

using namespace std;

int swap(int y)
{
    int res = ((y << 4) & 0xf0) | (y >> 4) & 0x0f;
    return res;
}

int main()
{
int x = 0;
cout<<"Enter a Hex Value:"<<endl;
scanf("%x",&x);
printf("0x%X\n",swap(x));
uint32_t num = 0xffffffff;
uint64_t n = 0xffffffffffffffff;
cout<<num<<endl;
cout<<n<<endl;7
printf("Hello World\n");
//printf("%x\n",num);
//printf("%d\n",num);
//printf("%o\n",num);
//printf("%b\n",num);
//
//printf("%x\n",n);
//printf("%d\n",n);
//printf("%o\n",n);
//printf("%b\n",n);
return 0;
}

