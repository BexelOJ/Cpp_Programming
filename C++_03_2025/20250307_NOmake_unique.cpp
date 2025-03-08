#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    int a;
    int b;
    Base(int x, int y) : a(x), b(y) {}
};

int main()
{
    // Using raw pointer to allocate memory
    Base *ptr = new Base(10, 20);
    cout << ptr->a << " " << ptr->b << endl;

    // Modify the values
    ptr->a = 30;
    ptr->b = 40;
    cout << ptr->a << " " << ptr->b << endl;

    // Manually creating a unique_ptr in C++11
    std::unique_ptr<Base> ptr1(new Base(50, 60)); // Manual creation
    cout << ptr1->a << " " << ptr1->b << endl;

    delete ptr;

    return 0;
}



