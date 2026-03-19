#include <iostream>

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}
    
    Counter& operator--() {  // Prefix --
        --value;
        return *this;
    }

    void print() { 
        std::cout << value << std::endl; 
    }
};

int main() {
    Counter c(5);
    --c;  // Calls operator--()
    c.print();  // Outputs 4
}


