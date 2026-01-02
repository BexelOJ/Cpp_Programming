#include <iostream>
using namespace std;

int main() {
    int a = 6;   // 0110
    int b = 3;   // 0011

    if(a and b){
        cout<<"Both a and b are non-zero\n"; // True, both are non-zero
    }
    if(a or b){
        cout<<"At least one of a or b is non-zero\n"; // True, at least one is non-zero
    }
    if(not a){
        cout<<"a is zero\n"; // False, a is non-zero
    }
    if(not b){
        cout<<"b is zero\n"; // False, b is non-zero
    }
    
    std::cout << "\na and b    = " << (a and b)    << "\n"; // 3
    std::cout << "a or b     = " << (a or b) << "\n\n"; // 7
    
    std::cout << "not a      = " << (not a) << "\n"; // 0
    std::cout << "not b      = " << (not b) << "\n\n"; // 0
    
    std::cout << "a and b    = " << (a && b) << "\n"; // 1
    std::cout << "a or b     = " << (a || b) << "\n\n"; // 1          
    
    std::cout << "not a      = " << (!a) << "\n"; // 0
    std::cout << "not b      = " << (!b) << "\n\n";
    
    std::cout << "a bitand b = " << (a bitand b) << "\n"; // 2
    std::cout << "a bitor b  = " << (a bitor b)  << "\n"; // 7
    std::cout << "a xor b    = " << (a xor b)    << "\n"; // 5

    return 0;
}

