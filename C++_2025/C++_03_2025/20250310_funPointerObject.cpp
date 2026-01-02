#include <iostream>
using namespace std;

class Base
{
    int a;
    int b;
public:
    int (*fptr)(int, int);
    Base(int x, int y, int (*z)(int, int)):a(x), b(y), fptr(z){
        cout<<"PC Called"<<endl;
    }
    Base(const Base &other)
    {
        cout<<"CC Called"<<endl;
        a = other.a;
        b = other.b;
        fptr = other.fptr;
    }
    ~Base()
    {
        cout<<"DE Called"<<endl;
    }
};

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
cout<<"Enter Two Numbers: "<<endl;
cin>>a>>b;

Base b1(a,b,add);
cout<<a<<" + "<<b<<" = "<<b1.fptr(a,b)<<endl<<endl;

Base b2(a,b,mul);
cout<<a<<" * "<<b<<" = "<<b2.fptr(a,b)<<endl<<endl;

Base *b3 = new Base(a,b,add);
cout<<a<<" + "<<b<<" = "<<b3->fptr(a,b)<<endl<<endl;

Base *b4 = new Base(*b3);
cout<<a<<" + "<<b<<" = "<<b4->fptr(a,b)<<endl<<endl;

delete b3;
delete b4;

return 0;
}


