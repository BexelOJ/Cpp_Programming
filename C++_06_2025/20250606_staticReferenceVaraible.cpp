#include <iostream>
using namespace std;

int& getStaticRef() {
    static int x = 42;
    return x;  // returning a reference to static variable
}

int main() {
    int& ref = getStaticRef();
    cout << "Value: " << ref << endl; // prints 42

    ref = 100; // modifies the static variable
    cout << "Modified Value: " << getStaticRef() << endl; // prints 100

    return 0;
}

