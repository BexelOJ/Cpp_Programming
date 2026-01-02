#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    int a;
    int b;
    
    Base() { cout << "Default Constructor Called" << endl; }

    Base(int z):a(z) { cout << "Parameterized Constructor Called" << endl; }
    
    Base(int x, int y):a(x),b(y){ cout << "Parameterized Constructor Called" << endl; }
    
    Base(const Base& other)
    {
        a = other.a;
        b = other.b;
        cout << "Copy Constructor Called" << endl;
    }
   
    ~Base() { cout << "Destructor Called" << endl; }
};


void UniquePointer()
{
    unique_ptr<Base> ptr1 = make_unique<Base>(50, 60);
    unique_ptr<Base> ptrs1 = make_unique<Base>();

    shared_ptr<Base> ptr2 = make_shared<Base>(70, 80);
    shared_ptr<Base> ptr3 = ptr2; // only one destructor will be called, thus delete the object, both objects points to the same object
    cout << ptr1->a << " " << ptr1->b << endl;
    cout << ptr2->a << " " << ptr2->b << endl;
    cout << ptr3->a+10 << " " << ptr3->b << endl;

    // Checking reference count
    cout << "Reference count for ptr2: " << ptr2.use_count() << endl;
    cout << "Reference count for ptr3: " << ptr3.use_count() << endl;
}

int main()
{

    UniquePointer();

    return 0;
}


/*

Parameterized Constructor Called
Default Constructor Called
Parameterized Constructor Called
50 60
70 80
80 80
Reference count for ptr2: 2
Reference count for ptr3: 2
Destructor Called
Destructor Called
Destructor Called

*/