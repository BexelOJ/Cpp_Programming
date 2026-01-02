#include <iostream>
using namespace std;

void printAndModify(const int* ptr) {
    cout << "Value before modification: " << *ptr << endl;

    // Remove constness
    int* modifiablePtr = const_cast<int*>(ptr);
    *modifiablePtr = 100;

    cout << "Value after modification: " << *ptr << endl;
}

int main() {
    int x = 42;
    const int* p = &x;

    cout<<*p<<endl;
    printAndModify(p);
    cout<<*p<<endl;
    
    return 0;
}

