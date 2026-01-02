#include <iostream>
using namespace std;

// Base class 1
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Base class 2
class Bird {
public:
    void fly() {
        cout << "Bird is flying" << endl;
    }
};

// Derived class that inherits from both Animal and Bird
class Sparrow : public Animal, public Bird {
public:
    void display() {
        cout << "Sparrow is a Bird as well as an Animal" << endl;
    }
};

int main() {
    // Create an object of Sparrow
    Sparrow s;
    Animal a;
    Bird b;
    // Call methods from both base classes
    s.eat();    // Inherited from Animal
    s.fly();    // Inherited from Bird
    s.display(); // Method in Sparrow class

    a.eat();    // Inherited from Animal
    b.fly();    // Inherited from Bird
    return 0;
}

/*
Animal is eating
Bird is flying
Sparrow is a Bird as well as an Animal
*/

