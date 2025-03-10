#include <iostream>
using namespace std;


int (*fptrAdd)(int, int);
int (*fptrMul)(int, int);

int add(int x, int y)
{
    return x + y;
}

int mul(int x, int y)
{
    return x * y;
}

int main()
{
int a=0, b=0;
cout<<"Enter two numbers: "<<endl;
cin>>a>>b;

fptrAdd = add;
fptrMul = mul;

cout<<a<<" + "<<b<<" = "<<fptrAdd(a,b)<<endl;
cout<<a<<" * "<<b<<" = "<<fptrMul(a,b)<<endl;
return 0;
}




