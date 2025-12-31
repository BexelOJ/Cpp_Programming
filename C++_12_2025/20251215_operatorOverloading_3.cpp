#include <iostream>

using namespace std;

class Base {
    int x;
    int* ptr;
public:
    Base(int a):x(a), ptr(new int(a)) {
        std::cout << "Regular Construtor called" << std::endl;
    }

    Base(const Base& other) { // copy construtor
        std::cout << "Copy Construtor called" << std::endl;
        x = other.x;
        ptr = other.ptr ? new int(*other.ptr) : nullptr;
    }

    Base& operator=(const Base& other) { // copy assignment operator
        std::cout << "Copy Assignment operator called " << std::endl;
        if (this != &other) {
            delete ptr;
            ptr = other.ptr ? new int(*other.ptr) : nullptr;
            x = other.x;
        }
        return *this;
    }

    Base operator+(const Base& other) const {
        return Base(x + other.x);
    }

    void display() {
        std::cout << "Result: "<< x << std::endl;
    }
    
    ~Base() {
        std::cout<<"Destructor called"<<std::endl;
    }

};

int main() {
    Base b1(10);
    Base b2(20);
    
    Base b3 = b1 + b2; // 
    b3.display();
    
    Base b4(0); 
    b4 = b1 + b2;  // copy assignment operator
    b4.display();

    Base b5(b2);
    b5.display();

    return 0;
}



