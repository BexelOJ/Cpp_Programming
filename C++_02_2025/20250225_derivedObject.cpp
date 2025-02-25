#include <iostream>

using namespace std;

class Base{
    int x;
public:
    int a;
    int b;
};

class Derived: public Base{
    int y;
public:
    int c;
    int d;
};



int main()
{
Base *bptr = new Base;
Derived *dptr = new Derived;
bptr->a=10;
bptr->b=20;
dptr->c=30;
dptr->d=40;
cout<<bptr->a<<endl;
cout<<bptr->b<<endl;
cout<<dptr->c<<endl;
cout<<dptr->d<<endl;
cout<<sizeof(*bptr)<<endl;
cout<<sizeof(*dptr)<<endl;
return 0;
}



