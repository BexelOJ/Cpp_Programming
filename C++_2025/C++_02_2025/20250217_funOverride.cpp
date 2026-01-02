#include <iostream>

using namespace std;

class Base
{
public:
    virtual void Display()
    {
        cout<<"Inside Base Class"<<endl;
    }
};

class Derived : public Base
{
public:
    void Display() override
    {
        cout<<"Display Inside Derived Class"<<endl;
    }
};

int main()
{
Base *ptr1 = new Base;
Base *ptr2 = new Derived;
ptr1->Display();
ptr2->Display();
// Derived *ptr3 = new Base; // Not possible - Derived Pointer with Base Object
Derived *ptr4 = new Derived;
//ptr3->Display();
ptr4->Display();

delete ptr1;
delete ptr2;
delete ptr4;

return 0;
}
