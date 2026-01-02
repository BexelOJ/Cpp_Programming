#include <iostream>

using namespace std;

int (*fptr[3])(int, int); // fun pointer declaration

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int divi(int x, int y)
{
    return x / y;
}

int main()
{
int a=0, b=0;
cout<<"Enter two Numbers: "<<endl;
cin>>a>>b;
fptr[0] = &add;
fptr[1] = &sub;
fptr[2] = &mul;
fptr[3] = &divi;

cout<<"Addtion Result: "<<fptr[0](a,b)<<endl;
cout<<"Subtration Result: "<<fptr[1](a,b)<<endl;
cout<<"Multiplication Result: "<<fptr[2](a,b)<<endl;
cout<<"Division Result: "<<fptr[3](a,b)<<endl;
return 0;
}


