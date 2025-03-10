#include <iostream>

using namespace std;

int (*fptr)(int, int); // function pointer declaration

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divi(int a, int b)
{
    return a / b;
}

int main()
{
int a=0, b=0;
cout<<"Enter two Decimal Values: "<<endl;
cin>>a>>b;

fptr = add;
cout<<a<<" + "<<b<<" = "<<fptr(a,b)<<endl;

fptr = sub;
cout<<a<<" - "<<b<<" = "<<fptr(a,b)<<endl;

fptr = mul;
cout<<a<<" * "<<b<<" = "<<fptr(a,b)<<endl;

fptr = divi;
cout<<a<<" / "<<b<<" = "<<fptr(a,b)<<endl;

}

