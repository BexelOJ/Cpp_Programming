#include <iostream>

class Base {
public:
    int a;
    int b;

    Base(int aa, int bb): a(aa), b(bb) {
        std::cout << "Base constructor called " << std::endl;
    }

    void displayBase() {
        std::cout << "Base Display" << std::endl;
    }
};

class Derived : public Base {
public:
    int c;
    int d;
    
    Derived(int aa, int bb, int cc, int dd):Base(aa, bb), c(cc), d(dd) {
        std::cout << "Derived constructor called " << std::endl;
    }

    void displayDerived() {
        std::cout << "Derived Display" << std::endl;
    }
};

int main() {
    Base* bb = new Base(1,2);
    Base* bd= new Derived(1,2,3,4);

    //Derived* db = new Base(16,17);
    Derived* dd = new Derived(11,12,13,14);
    
    std::cout << bb->a << std::endl;
    std::cout << bb->b << std::endl;
    
    std::cout << bd->a << std::endl;
    std::cout << bd->b << std::endl;
    //std::cout << bd->c << std::endl;
    //std::cout << bd->d << std::endl;

    //std::cout << db->a << std::endl;
    //std::cout << db->b << std::endl;
    //std::cout << db->c << std::endl;
    //std::cout << db->d << std::endl;

    std::cout << dd->a << std::endl;
    std::cout << dd->b << std::endl;
    std::cout << dd->c << std::endl;
    std::cout << dd->d << std::endl;

    bb->displayBase();
    
    bd->displayBase();
    //bd->displayDerived();

    dd->displayBase();
    dd->displayDerived();

    return 0;
}



