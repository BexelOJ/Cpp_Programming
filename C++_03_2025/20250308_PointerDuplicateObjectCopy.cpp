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

void ObjectInStack()
{
    Base b1;  // object b1 in Stack Memory
    b1.a = 2;
    b1.b = 5;
    cout << b1.a << " " << b1.b << endl;
    
    Base b2 = b1;  
    b2.a = 4;
    b2.b = 7;
    cout << b2.a << " " << b2.b << endl;
    cout << b1.a << " " << b1.b << endl;
    
    Base b3(b1);
    b3.a = 8;
    b3.b = 9;
    cout << b3.a << " " << b3.b << endl;
    cout << b2.a << " " << b2.b << endl;
    cout << b1.a << " " << b1.b << endl;

    Base b4(100);  // object b1 in Stack Memory
    cout <<b4.a << endl;
}

void ObjectInHeap()
{
    Base* ptr1 = new Base(10, 20);   // object is in Heap Memory with raw pointer 'ptr'
    cout << ptr1->a << " " << ptr1->b << endl;

    ptr1->a = 30;
    ptr1->b = 40;
    cout << ptr1->a << " " << ptr1->b << endl;

    Base* ptr2 = ptr1;  // not an object copy, it's just a pointer copy
    cout << ptr2->a << " " << ptr2->b << endl;

    ptr2->a = 130;
    ptr2->b = 140;
    cout << ptr2->a << " " << ptr2->b << endl;
    cout << ptr1->a << " " << ptr1->b << endl;

    Base* ptr3 = new Base(*ptr1); // Copy constructor is called to create a new object

    cout << ptr3->a << " " << ptr3->b << endl;

    ptr3->a = 150;
    ptr3->b = 160;
    cout << ptr3->a << " " << ptr3->b << endl;
    cout << ptr2->a << " " << ptr2->b << endl;
    cout << ptr1->a << " " << ptr1->b << endl;

    delete ptr1;  // both pointer ptr and ptr1 points to same object, so deleteing one pointer is enough.
    delete ptr3;

}

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
    ObjectInStack();
    ObjectInHeap();
    UniquePointer();

    return 0;
}




/* OUTPUT:

Default Constructor Called
2 5
Copy Constructor Called
4 7
2 5
Copy Constructor Called
8 9
4 7
2 5
Parameterized Constructor Called
100
Destructor Called
Destructor Called
Destructor Called
Destructor Called
Parameterized Constructor Called
10 20
30 40
30 40
130 140
130 140
Copy Constructor Called
130 140
150 160
130 140
130 140
Destructor Called
Destructor Called
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



