#include <iostream>
#include <algorithm>
#include <memory> 

using namespace std;

class Base_1 { 
public: 
    int x; 
    int y;
    Base_1(int a, int b) : x(a), y(b) {
    
    } 
};

class Base_2 { 
public: 
    int a;
    int b;
    Base_2(int x,int y) : a(x), b(y) {
    
    } 
};

class Combined {
    Base_1 part1;
    Base_2 part2;

public:
    // Copy constructor from two objects
    Combined(const Base_1& obj1, const Base_2& obj2): part1(obj1), part2(obj2) {
    
    }
    
    // Move constructor (efficient)
    Combined(Base_1&& obj1, Base_2&& obj2): part1(std::move(obj1)), part2(std::move(obj2)) {
    
    }

    void display() {
        std::cout << "part1.x : " << part1.x << std::endl;
        std::cout << "part1.x : " << part1.y << std::endl;
        std::cout << "part2.y : " << part2.a << std::endl;
        std::cout << "part1.x : " << part2.b << std::endl;
      // std::cout << "Size of Object: " << sizeof(part2) << std::endl;
    }

    void increment() {
        part1.x++;
        part1.y++;
        part2.a++;
        part2.b++;
    }
};

int main() {
    Base_1 obj1(10, 20);
    Base_2 obj2(30, 40);
    
    Combined obj3(obj1, obj2);           // Copy
    Combined obj3_move(std::move(obj1), std::move(obj2));  // Move [web:104]

    obj3.display();
    
    std::cout << "Size of obj1 : " << sizeof(obj1) << std::endl;
    std::cout << "Size of obj2 : " << sizeof(obj2) << std::endl;
    std::cout << "Size of obj3 : " << sizeof(obj3) << std::endl;
    std::cout << "Size of obj3_move : " << sizeof(obj3_move) << std::endl;

    obj3_move.display();
    obj3_move.increment();
    obj3_move.display();

    return 0;
}



