#include <iostream>
using namespace std;

int callBack(int a, int b, int (*fptr)(int, int))
{
    return fptr(a,b); 
}

int add(int x, int y)
{
 return x+y;
}

int sub(int x, int y)
{
 return x-y;
}

int mul(int x, int y)
{
 return x*y;
}

int divi(int x, int y)
{
 return (x/y);
}


int main()
{
int a = 0 , b = 0;
cout<<"Enter the values of a and b: "<<endl;
cin>>a>>b;

//int res = 0;
int resA = callBack(a,b,add);
int resS = callBack(a,b,sub);
int resM = callBack(a,b,mul);
int resD = callBack(a,b,divi);
cout<<"Addition: "<<resA<<endl;
cout<<"Subtraction: "<<resS<<endl;
cout<<"Multiplication: "<<resM<<endl;
cout<<"Division: "<<resD<<endl;
return 0;
}


