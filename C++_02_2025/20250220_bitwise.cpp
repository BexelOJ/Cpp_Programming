#include <iostream>

using namespace std;

int main()
{
int a = 0xff;
printf("%d\n",a);
printf("%x\n",a);
int b = (a & 0xfe);
printf("%X\n",b);
return 0;
}




