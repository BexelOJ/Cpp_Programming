#include <iostream>

using namespace std;

class Base
{
public:
    char z;
    char x;
    int a;
    char y;
    int b;
};

class Derived: public Base
{
public:
    int c;
    char e;
    int d;
};

int main()
{
Base *objB1 = new Derived;
Base *objD1 = new Derived;
objB1->a=10;
objD1->a=50;
cout<<++(objB1->a)<<endl;
cout<<(objD1->a)<<endl;
return 0;
}



