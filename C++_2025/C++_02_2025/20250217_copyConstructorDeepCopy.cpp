#include <iostream>

class Base {
private:
    int a;
    int b;
public: 
    int c;
    Base(int x, int y, int z) : a(x), b(y), c(z) {
        std::cout << "Base Constructor Called" << std::endl;
    }
    
    // Copy constructor (deep copy)
    Base(const Base& other) {
        std::cout << "Base Copy Constructor Called" << std::endl;
        a = (other.a + 1);
        b = (other.b + 1);
        c = (other.c + 1);
    }

    void Display() {
        std::cout << "Inside Base Class " <<a <<" " <<b <<" "<<c<< std::endl;
    }
};

int main() {
    // Create object on stack
    Base sb(50,60,70);
    sb.Display();

    Base sc = sb;
    sc.Display();
    
    // Create object on heap
    Base* b3 = new Base(1, 2, 3);

    // Create a copy on the heap
    Base* b4 = new Base(*b3); // Calls the copy constructor

    // Display objects on Heap
    b3->Display();
    b4->Display();

    // Free the heap allocated memory
    delete b3;
    delete b4;

    return 0;
}

/*
// Output:

Base Constructor Called
Base Copy Constructor Called
Inside Base Class
1 and 2
Inside Base Class
1 and 2

*/