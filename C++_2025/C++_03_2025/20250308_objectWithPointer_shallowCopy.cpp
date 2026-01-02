#include <iostream>
using namespace std;

class Base {
public:
    int size;
    int* ptr;

    Base() { 
        std::cout << "Default Constructor Called" << std::endl; 
    }

    Base(int x):size(x) {
        std::cout <<"Parameterized Constructor Called" << std::endl;
        //ptr = new int[size];
    }

    Base(const Base& other) {
        std::cout << "Copy Constructor Called" << std::endl;
    }

    Base& operator=(const Base& other) {
        std::cout << "Copy Assignment Operator Called" << std::endl;
        return *this;
    }

    ~Base() {
        std::cout << "Destructor Called" << std::endl;
        //delete ptr;
    }
};

int add(int a, int b)
{
    Base b1(10);
    Base b2 = b1; // copy constructor 
    return a + b;
}

int mul(int a, int b)
{
    Base *ptrObj1 = new Base;
    Base *ptrObj2 = new Base(20);
    Base *ptrObj3 = new Base(*ptrObj2);
    Base* ptrObj4;
    ptrObj4 = new Base(*ptrObj2);

    delete ptrObj1;
    delete ptrObj2;
    delete ptrObj3;
    delete ptrObj4;

    return a * b;
}

int main()
{
    int a = 0, b = 0;
    std::cout<<"Enter two numbers: "<< std::endl;
    cin >>a>> b;
    std::cout << add(a, b) << std::endl;
    std::cout << mul(a, b) << std::endl;
    return 0;
}


