#include <iostream>
#include <algorithm>

using namespace std;

class Calculator {
    int a, b;
public:
    Calculator(int l, int m): a(l), b(m){
        std::cout << "Parameterized Construtor Called" << std::endl;
    }

    // for funPtr_1
    int add(int x, int y) {
        return x + y;
    }

    // for funPtr_2
    int add() const {
        return a + b;
    }

};



int main() {
    int x = 0, y = 0, res_1 = 0, res_2 = 0;

    std::cout << "Enter two numbers : " << std::endl;
    std::cin >> x >> y;

    Calculator c1(x, y);

    // Two ways to use function pointer with class
    int(Calculator::*funPtr_1)(int, int) = &Calculator::add;
    int(Calculator::*funPtr_2)() const = &Calculator::add;    
    
    funPtr_1 = &Calculator::add;
    funPtr_2 = &Calculator::add;

    res_1 = (c1.*funPtr_1)(x, y);
    res_2 = (c1.*funPtr_2)();

    std::cout << "Final Result 1 : " << res_1 << std::endl;
    std::cout << "Final Result 2 : " << res_2 << std::endl;

    return 0;
}

