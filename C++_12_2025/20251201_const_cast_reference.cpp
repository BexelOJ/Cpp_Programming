#include <iostream>
using namespace std;

int main() {
    int val = 42;
    const volatile int* cv_ptr = &val;  // Pointer to const volatile int
    
    // Cannot modify through cv_ptr due to qualifiers
    // *cv_ptr = 100;  // Compile error!
    
    // Remove both const and volatile qualifiers
    int* mutable_ptr = const_cast<int*>(cv_ptr);
    *mutable_ptr = 100;  // Now modifiable - safe since val is non-const
    
    cout << "Modified value: " << val << endl;  // Prints 100
    return 0;
}



