// Step 1: Define the Abstract Class (Base Class)
#include <iostream>

// Abstract class defining the template method
class Cooking {
public:
    // Template method defining the structure of the algorithm
    void cook() {
        prepareIngredients();
        cookFood();
        serve();
    }

    // Default implementation for some steps
    virtual void prepareIngredients() {
        std::cout << "Preparing ingredients..." << std::endl;
    }

    // Abstract method, to be implemented by subclasses
    virtual void cookFood() = 0;

    // Default implementation for serving the food
    virtual void serve() {
        std::cout << "Serving the food!" << std::endl;
    }

    virtual ~Cooking() = default;
};


// Step 2: Create Concrete Classes (Child Classes)
// Concrete Class: Cooking Pasta
class CookingPasta : public Cooking {
public:
    void cookFood() override {
        std::cout << "Boiling water and cooking the pasta..." << std::endl;
    }
};


// Concrete Class: Cooking Steak
class CookingSteak : public Cooking {
public:
    void cookFood() override {
        std::cout << "Grilling the steak..." << std::endl;
    }
};

//  Step 3: Using the Template Method in the Client Code
int main() {
    // Create an object of CookingPasta
    Cooking* pasta = new CookingPasta();
    std::cout << "Cooking Pasta:" << std::endl;
    pasta->cook(); // Template method is called
    std::cout << std::endl;

    // Create an object of CookingSteak
    Cooking* steak = new CookingSteak();
    std::cout << "Cooking Steak:" << std::endl;
    steak->cook(); // Template method is called
    std::cout << std::endl;

    delete pasta;
    delete steak;

    return 0;
}


/*
OUTPUT:

Cooking Pasta:
Preparing ingredients...
Boiling water and cooking the pasta...
Serving the food!

Cooking Steak:
Preparing ingredients...
Grilling the steak...
Serving the food!

*/