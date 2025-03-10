#include <iostream>
using namespace std;

class Base {
public:
    int size;
    int* ptr;
    Base():size(0), ptr(nullptr) { cout << "Default Constructor Called" << endl; }

    Base(int x) :size(x) {
        cout << "Parameterized Constructor Called" << endl;
        ptr = new int[size];
    }
    
    ~Base() {
        cout << "Destructor Called" << endl;
        //delete ptr;
    }
     Base(const Base &other) {
         cout << "Copy Constructor Called" << endl;
            size = other.size;
            ptr = new int[size];
            for (int i = 0; i < size; i++) {
                ptr[i] = other.ptr[i];
            }
        }

     //Base& operator=(const Base &other) {
         /*   if (this != &other) {
                delete[] ptr;
                size = other.size;
                ptr = new int[size];
                for (int i = 0; i < size; i++) {
                    ptr[i] = other.ptr[i];
                }
            }
            return *this;
        }*/
    
};

int add(int a, int b)
{
    Base b1(10);
    Base b2 = b1;
    return a + b;
}

int mul(int a, int b)
{
    Base* ptrObj1 = new Base;
    Base* ptrObj2 = new Base(20); 
    Base* ptrObj3 = new Base(*ptrObj2);
    delete ptrObj1;
    delete ptrObj2;
    delete ptrObj3;
    return a * b;
}

int main()
{
    int a = 0, b = 0;
    cout<<"Enter two numbers: "<<endl;
    cin >> a >> b;
    cout << add(a, b) << endl;
    cout << mul(a, b) << endl;
    return 0;
}


