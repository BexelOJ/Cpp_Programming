#include <iostream>
#include <cstdint>

using namespace std;

void display(uint8_t x)
{
for(int i=7; i>=0; i--)
    printf("%b",((x >> i)&1));
cout<<endl;   
printf("%d\n",x);
printf("%x\n",x);
printf("%o\n",x);
printf("%b\n",x);
}

int main()
{
uint8_t num=0;
int n=0;
cout<<"Enter a Decimal Number: "<<endl;
cin>>n;
num = n;
cout<<sizeof(uint8_t)<<endl;
display(num);
return 0;
}

