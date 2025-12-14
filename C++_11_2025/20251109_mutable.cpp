#include <iostream>

using namespace std;

class Animal {
public:
    int a;
    mutable int b;

    Animal(int value_1, int value_2) :a(value_1), b(value_2) {
        cout << "Construtor Called" << endl;
    }

    void Modify() {
        b = 10;
    }

    int getter_a() {
        return a;
    }

    int getter_b() {
        return b;
    }
};

int main() {
    Animal a1(60,70);
    
    std::cout << "Value of a = " << a1.a << endl;
    std::cout << "Value of b = " << a1.b << endl;
    a1.Modify();
    std::cout << "Value of b = " << a1.b << endl;

    //std::cout << "Value of a = " << a1.getter_a << endl;
    //std::cout << "Value of b = " << a1.getter_b << endl;

    return 0;
}


