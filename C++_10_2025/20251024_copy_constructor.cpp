#include <iostream>

using namespace std;

class Base {
private:

public:
    virtual void display() {
        std::cout << "Base class Display called" << std::endl;
    }

};

class Derived :public Base {
private:

public:
    void display() {
        std::cout << "Derived class Display called" << std::endl;
    }
};

int main() {
    Base b1;
    Derived b2;
    b1.display();
    b2.display();

    Base* ptr1;

    int choice=0;
    std::cout << "Enter the Choice 1 or 2" << std::endl;
    std::cin >> choice;
    
    if (choice == 1)
    {   
       ptr1 = new Base();
    }
    else if (choice == 2) {
       ptr1 = new Derived();
    }

    ptr1->display();

    return 0;
}


