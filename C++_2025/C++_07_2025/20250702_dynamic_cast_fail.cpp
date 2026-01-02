#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}  // RTTI enabled
};

class Derived : public Base {
public:
    void hello() { std::cout << "Hi from Derived\n"; }
};

int main(){
Base* b = new Base();  
Derived* d = dynamic_cast<Derived*>(b);  // Condition 2: ✔️ RTTI works

if (d)
    d->hello();  // Works!
else
    cout << "dynamic_cast failed" << endl;
return 0;
}

/*
Output:

dynamic_cast failed

*/

