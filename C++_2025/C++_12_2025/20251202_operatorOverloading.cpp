#include <iostream>
#include <algorithm>

using namespace std;

class Square {
    int a, b;
public:
    
    Square(int val_1=0, int val_2=0) : a(val_1), b(val_2){
        
    }

    Square operator+(const Square& other) const {
        
        return Square(a + other.a, b + other.b);

    }

    void display()  {
        std::cout << "( " << a << " + " << b << " )" << std::endl;
    }
};

int main() {
    Square s1(1,2), s2(3,4);
    
    Square s3 = s1 + s2;  // Square s3 = s1.operator+(s2);
        s3.display();

    Square s4;
    s4= s1 + s2;  
    s4.display();

    return 0;
}

