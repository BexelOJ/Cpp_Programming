#include <iostream>
#include <string>

// Abstract Product
class Animal {
public:
    virtual void speak() = 0; // Pure virtual function
    virtual ~Animal() = default;
};

// Concrete Product 1
class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Concrete Product 2
class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Creator
class AnimalFactory {
public:
    virtual Animal* createAnimal() = 0; // Factory method
    virtual ~AnimalFactory() = default;
};

// Concrete Creator 1
class DogFactory : public AnimalFactory {
public:
    Animal* createAnimal() override {
        return new Dog(); // Return a Dog object
    }
};

// Concrete Creator 2
class CatFactory : public AnimalFactory {
public:
    Animal* createAnimal() override {
        return new Cat(); // Return a Cat object
    }
};

int main() {
    // Create a factory object
    AnimalFactory* dogFactory = new DogFactory();
    Animal* dog = dogFactory->createAnimal();
    dog->speak(); // Output: Woof!

    AnimalFactory* catFactory = new CatFactory();
    Animal* cat = catFactory->createAnimal();
    cat->speak(); // Output: Meow!

    // Clean up
    delete dog;
    delete dogFactory;
    delete cat;
    delete catFactory;

    return 0;
}

/*
OUTPUT:

Woof!
Meow!

*/