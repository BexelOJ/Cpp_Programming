#include <iostream>

using namespace std;

class Base {
    int a;
    int b;
public:
    Base(int x, int y) :a(x), b(y) {
    
    }
    
    void swapAndDisplay() {
        a = a + b;
        b = a - b;
        a = a - b;
        std::cout << " After Swap: " << std::endl;
        std::cout << " a =  "<<a<< std::endl;
        std::cout << " b =  " << b << std::endl;
    }
};

int main() {
    int a=0, b = 0;
    std::cout << "Enter two values: " << std::endl;
    std::cin >> a>> b;

    if ((a < 10) and (b < 10)){
        Base b1(a, b);
        std::cout << "Stack: " << std::endl;
        b1.swapAndDisplay();
    }
    else {
        Base* b2 = new Base(a, b);
        std::cout << "Heap: " << std::endl;
        b2->swapAndDisplay();
    }

    
    return 0;
}



