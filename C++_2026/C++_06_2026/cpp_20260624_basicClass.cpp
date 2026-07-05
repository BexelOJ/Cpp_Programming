#include <iostream>

class Base {

public:
    int a = 10;
    Base(int x = 5):a(x) {}

    void show() {
        std::cout << "Value in Base Class : " << a << std::endl;
    }
};

class Derived : public Base {

public:
    int b = 20;
    Derived(int y = 6): b(y) {}

    void show() {
        std::cout << "Value in Drvd Class : " << b << std::endl;
    }
};

int main() {
    Base b1;
    Base* b2 = new Base(600);

    Derived d1;
    Derived* d2 = new Derived(700);

    b1.show();
    d1.show();
    b2->show();
    d2->show();

    delete b2;
    delete d2;

    return 0;
}



