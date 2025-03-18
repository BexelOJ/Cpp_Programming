#include <iostream>

using namespace std;

class Base {
public:
    int a;
    int b;
    Base(int x, int y) : a(x), b(y) {
        cout << "Base Parameterized Construtor Called" << endl;
    }
    void display()
    {
        cout << a << " " << b << endl;
    }
};

class Derived : public Base {
public:
    int c;
    int d;
    Derived(int x, int y, int s, int t) : Base(x, y), c(s), d(t) {
        cout << "Derived Parameterized Construtor Called" << endl;
    }
    void display()
    {
        cout << a << " " << b << " " << c << " " << d << endl;
    }
};

int main()
{
    Base* ptr1 = new Base(10, 20);
    ptr1->display();
    Derived* ptr2 = new Derived(10, 20, 30, 40);
    ptr2->display();
  /*  Derived* ptr3 = new Base(100, 200);
    ptr3->display();*/
    return 0;
}

