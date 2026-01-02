#include <iostream>

using namespace std;

class Base{
public:
    int a;
    int b;
//public:
    Base(int x, int y):a(x),b(y){

    }
};

class Derived: public Base{
public:
    int c;
    int d;
    Derived(int x, int y, int p, int q):Base(x,y), c(p), d(q){

    }
};

int main()
{
Base *Bptr = new Base(10,20);
cout<<Bptr->a<<endl;
cout<<Bptr->b<<endl;
Derived *Dptr = new Derived(30,40,50,60); 
cout<<Dptr->a<<endl;
cout<<Dptr->b<<endl;
cout<<Dptr->c<<endl;
cout<<Dptr->d<<endl;
return 0;
}


