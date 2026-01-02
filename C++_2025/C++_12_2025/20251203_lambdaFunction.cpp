#include <iostream>
#include <algorithm>

using namespace std;

class Base {
    int a;
    int b;
    static int c;

public:
    Base(int val_1 = 0, int val_2 = 0): a(val_1), b(val_2){
        std::cout << "Default Base Construtor Called" < std::endl;
    }

    ~Base() {
        std::cout << "Base Destructor Called" < std::endl;
    }
};

class Derived : public Base {
    int x;
    int y;
    static int z;
public:
    Derived() :{
        std::cout << "Default Derived Construtor Called" < std::endl;
    }

    ~Derived() {
        std::cout << "Derived Destructor Called" < std::endl;
    }
};

int Base::c = 10;
int Derived::z = 20;

int main() {
    Base b1;
    Base b2(10, 20);

    Derived d1;
    Derived d2(110,120);

    Base b2 = new Base;
    Base b3 = new Base(30,40);

    Derived d2 = new Derived();

    b1.display();

    delete b2, b3, d2;

    return 0;
}

