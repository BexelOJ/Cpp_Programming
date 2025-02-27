#include <iostream>

using namespace std;

class Base{
private:
    const int a;
    static int b;
    const int &c=a;
public:
    Base(int x):a(x)
    {
        cout<<"Parameterized Constructor called"<<endl;
    }

static void setter(int val)
{
    b = val;
}

int getter()
{
    int r = b;
    return r;
}

};

int Base::b = 20;

int main()
{
Base b1(10);
//b1.setter(200);
cout<<b1.getter()<<endl;
//cout<<Base::b<<endl;
return 0;
}

