#include <iostream>
#include <algorithm>

using namespace std;

class Base {
    int a;
    int b;
public:
    Base(int x=0, int y=0) :a(x), b(y) {
        std::cout << "Base Construtor Called " << std::endl;
    }

    ~Base() {
        std::cout << "Base Destructor Called" << std::endl;
    }

     virtual void display() {
        std::cout << this->a << ", " << this->b << std::endl;
    }
};


class Derived : public Base{
    int x;
    int y;
public:
    Derived(int a=0, int b=0): Base(a,0), x(a), y(b){
        std::cout << "Derived Construtor Called " << std::endl;
    }

    ~Derived() {
        std::cout << "Derived Destructor Called" << std::endl;
    }

    void display() {
        std::cout << this->x <<", "<< this->y << std::endl;
    }
};


int main() {

    Base* b11 = new Base();
    std::cout << sizeof(*b11) << std::endl;

    Base* b14 = new Derived(256, 512);
    Derived* b15 = new Derived(256, 512);

    std::cout <<"Sizeof b14 = " << sizeof(*b14) << std::endl;
    std::cout <<"Sizeof b15 = " <<sizeof(*b15) << std::endl;

    b11->display();
    b14->display();
    b15->display();

    delete b11;
    delete b14;
    delete b15;
    
    return 0;
}

