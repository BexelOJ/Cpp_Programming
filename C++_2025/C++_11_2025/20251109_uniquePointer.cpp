#include <iostream>
#include <memory>

using namespace std;

class Base{
public: 
    int value;
    Base(int v) : value(v) {
      std::cout<<"Para Construtor called"<<std::endl;
    }

    ~Base() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    std::unique_ptr<Base> ptr1 {new Base(10)};
    std::unique_ptr<Base> ptr4 (new Base(40));
    //std::unique_ptr<Base> ptr1 {new Base(10)};

    auto ptr2 = std::make_unique<Base>(20);

    Base* ptr3 = new Base(30);
    Base obj(50);

    std::cout << ptr1->value << std::endl;
    std::cout << ptr2->value << std::endl;
    std::cout << ptr3->value << std::endl;
    std::cout << ptr4->value << std::endl;
    std::cout << obj.value << std::endl;

    delete ptr3;

    return 0;
}








