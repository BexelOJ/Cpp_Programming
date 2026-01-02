#include <iostream>

using namespace std;

class Base{
public:
int a;
int b;
void Display(){
    cout<<"Inside Base Class"<<endl;
}
};

class Derived: public Base{
public:
void Display(){
    cout<<"Inside Derived Class"<<endl;
}
};

int main()
{
Base *ptr1 = new Base;
Base *ptr2 = new Derived;
Derived *ptr3 = new Derived;

ptr1->Display();
ptr2->Display();
ptr3->Display();
return 0;
}


