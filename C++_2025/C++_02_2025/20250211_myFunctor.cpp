#include <iostream>

class Myclass
{
private:
        int value;

public:
int operator()(int v)//:value(v)
{
    std::cout<<"\nFunction Object called with value : "<<v<<std::endl;
    std::cout<<v<<" * "<<v<<" is : ";
    return v*v;
}
};


int main()
{
int a=0;

std::cout<<"Enter a value: "<<std::endl;
std::cin>>a;

Myclass m1;

std::cout<<m1.operator()(a)<<std::endl;  // actual operation of overloaded operator '()', to use object as a function.

std::cout << m1(25) << std::endl;  // calling object as a function.

return 0;
}

/*
OUTPUT:
Enter a value:
15

Function Object called with value : 15
15 * 15 is : 225

Function Object called with value : 25
25 * 25 is : 625

*/

