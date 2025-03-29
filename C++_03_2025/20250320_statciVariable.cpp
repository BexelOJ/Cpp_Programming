#include <iostream>

using namespace std;

class Base {
    int a;
public:
    static const int b=10;
    static int c;
    int &r = c;
};

int Base :: c = 20;

int main()
{
    Base b1;
    cout << b1.b << endl;
    cout << b1.c << endl;
    cout << b1.r << endl;
    return 0;
}


