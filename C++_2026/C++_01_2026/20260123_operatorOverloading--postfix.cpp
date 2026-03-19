#include <iostream>

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter operator--(int) {  // Postfix -- (int distinguishes it)
        Counter temp = *this;
        --value;
        return temp;
    }

    void print() {
        std::cout << value << std::endl;
    }
};

int main() {
    Counter c(5);
    Counter prev = c--;  // Calls operator--()
    c.print();  // Outputs 4
    prev.print();
}


