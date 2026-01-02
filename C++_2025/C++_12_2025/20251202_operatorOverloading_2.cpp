#include <iostream>
#include <algorithm>

using namespace std;

class Base {
    int size;
    int* ptr;
public:
   
    /* Base() {
        std::cout << " Parameterized Constructor Called" << std::endl;
    }
    */

    Base(int val_1 = 0): size(val_1), ptr(nullptr) {
        std::cout << " Parameterized Constructor Called" << std::endl;
    
    }

    ~Base() {
        std::cout << " Destructor Called" << std::endl;
    
    }
};


int main() {
    Base b1;
    return 0;
}

