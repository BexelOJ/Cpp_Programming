#include <iostream>

int CallbackReceiverFunction(int a, int b, int (*fptr)(int, int))
{
    return fptr(a,b); // calling the function and returning the result
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
std::cout<<"Enter the values of a and b: "<<std::endl;
std::cin>>a>>b;

//int res = 0;
int resA = CallbackReceiverFunction(a,b,add);   // add is the callback function
int resS = CallbackReceiverFunction(a,b,sub);   // sub is the callback function
int resM = CallbackReceiverFunction(a,b,mul);   // mul is the callback function
int resD = CallbackReceiverFunction(a,b,divi);  // divi is the callback function

std::cout<<"Addition: "<<resA<< std::endl;
std::cout<<"Subtraction: "<<resS<< std::endl;
std::cout<<"Multiplication: "<<resM<< std::endl;
std::cout<<"Division: "<<resD<< std::endl;
return 0;
}

//"Higher-Order Function" or "Callback Receiver Function"

/*
OUTPUT:
Enter the values of a and b:
15 5
Addition: 20
Subtraction: 10
Multiplication: 75
Division: 3

*/

