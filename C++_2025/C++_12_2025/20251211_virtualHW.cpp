#include <iostream>
#include <cstring>

using namespace std;

class Base{

public:
    int bx;
    int by;

    Base(int a, int b):bx(a), by(b){
        std::cout << "Base Constructor called" << std::endl;
    }

    virtual void show() {
        std::cout << " bx = " << bx << std::endl;
        std::cout << " by = " << by << std::endl << std::endl;
    }
};

class Derived: public Base {

public:
    int dx;
    int dy;
    
    Derived(int a=0, int b=0):Base(1,2), dx(a), dy(b){
        std::cout << "Derived Construcotr called" << std::endl;
    }

    void show() {
        std::cout << " bx = " << bx << std::endl;
        std::cout << " by = " << by << std::endl;
        std::cout << " dx = " << dx << std::endl;
        std::cout << " dy = " << dy << std::endl << std::endl;
    }
};

int main(){
    Base* b1 = new Base(1,2);
    b1->show();

    Derived* d1 = new Derived(3,4);
    d1->show();
    
    Base* b2 = new Derived(3,4);
    b2->show();
    
    return 0;
}

