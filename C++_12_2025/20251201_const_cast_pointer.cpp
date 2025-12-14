#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const volatile int val = 20;
    const volatile int* ptr = &val;

    int* mutable_ptr = const_cast<int*>(ptr);

    *mutable_ptr = 30;

    std::cout << *mutable_ptr << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << val << std::endl;
    return 0;
}



/*
* 
* Perplexity Code
*
#include <iostream>
using namespace std;

void modify(int* ptr) {
    *ptr = 20;  // Modifies the value pointed to
}

int main() {
    const int val = 10;
    const int* constPtr = &val;

    // Remove constness to pass to modify()
    int* modifiablePtr = const_cast<int*>(constPtr);
    modify(modifiablePtr);

    cout << "Modified value: " << *constPtr << endl; // May print 20 or cause undefined behavior
    return 0;
}

*/




