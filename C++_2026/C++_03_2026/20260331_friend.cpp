#include <iostream>

class Shape{
    int length;
    int breadth;
public:
    Shape(int x, int y):length(x), breadth(y){
        std::cout << "Parameterized Constructor called" << std::endl;
    };

    void display(){
        std::cout << "Value of Length : " <<length<< std::endl;
        std::cout << "Value of Breadth : " << breadth << std::endl;
    }

    friend int Area_1(Shape& other);
    friend void Area_2(Shape& other);
};

int Area_1(Shape& other) {
    return other.length * other.breadth;
}

void Area_2(Shape& other) {
    std::cout<<"Area : "<<other.length * other.breadth<<std::endl;
}

int main() {
    Shape b1(5,6);
    b1.display();
    Shape* b2 = new Shape(15,4);
    
    std::cout << "Area : " << Area_1(b1) << std::endl;
    std::cout << "Area : " << Area_1(*b2) << std::endl;

    Area_2(b1);
    Area_2(*b2);

    return 0;
}

/*
OUTPUT:

Parameterized Constructor called
Value of Length : 5
Value of Breadth : 6
Parameterized Constructor called
Area : 30
Area : 60
Area : 30
Area : 60

*/



