#include <iostream>

using namespace std;

class Base
{
public:
    int size;
    int* ptr;
public:
    Base() :size(0), ptr(nullptr) { 
        cout << "Default Constructor called " << endl; 
    }
    
    Base(int a) :size(a),ptr(new int[a]) {
        cout << "Parameterized Constructor called " << endl;
        // ptr = new int[size];
    }

    Base(const Base& other)
    {
        cout << "Copy Constructor called " << endl;
        size = other.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }

    ~Base() {
        cout << "Destructor called " << endl;
        delete[] ptr;
    }
};

int main()
{
    Base b1;
    Base b2(10);
    
    Base b3 = b2;
    Base b4(b2);

    Base* ptrO1 = new Base;
    Base* ptrO2 = new Base(20);
    Base* ptrO3 = new Base(*ptrO1);
    Base* ptrO4 = new Base(*ptrO2);

    delete ptrO1;
    delete ptrO2;
    delete ptrO3;
    delete ptrO4;
   
    return 0;
}


