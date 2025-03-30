// Step 1: Define the Component Interface
#include <iostream>
#include <string>

// Component interface
class Car {
public:
    virtual void assemble() = 0;  // A method to assemble the car
    virtual ~Car() = default;
};


// Step 2: Define the Concrete Component
// ConcreteComponent
class BasicCar : public Car {
public:
    void assemble() override {
        std::cout << "Basic Car." << std::endl;  // Assemble a basic car
    }
};

// Step 3: Define the Decorator Base Class
// Decorator class implements the same interface as Component
class CarDecorator : public Car {
protected:
    Car* car;  // A reference to a Car object

public:
    CarDecorator(Car* car) : car(car) {}

    void assemble() override {
        car->assemble();  // Delegate the responsibility to the car
    }

    virtual ~CarDecorator() = default;
};


// Step 4: Define Concrete Decorators
// ConcreteDecorator 1 - Adding Sunroof
class Sunroof : public CarDecorator {
public:
    Sunroof(Car* car) : CarDecorator(car) {}

    void assemble() override {
        CarDecorator::assemble();  // Call the base class assemble
        std::cout << "Adding Sunroof." << std::endl;  // Add sunroof feature
    }
};

// ConcreteDecorator 2 - Adding Leather Seats
class LeatherSeats : public CarDecorator {
public:
    LeatherSeats(Car* car) : CarDecorator(car) {}

    void assemble() override {
        CarDecorator::assemble();  // Call the base class assemble
        std::cout << "Adding Leather Seats." << std::endl;  // Add leather seats feature
    }
};


// Step 5: Client Code
int main() {
    Car* sportsCar = new BasicCar();  // A basic car

    std::cout << "Assembling Sports Car: " << std::endl;
    sportsCar->assemble();  // Assemble a basic car

    std::cout << "\nAssembling Sports Car with Sunroof: " << std::endl;
    Car* sportsCarWithSunroof = new Sunroof(sportsCar);  // Add sunroof decorator
    sportsCarWithSunroof->assemble();  // Assemble car with sunroof

    std::cout << "\nAssembling Sports Car with Sunroof and Leather Seats: " << std::endl;
    Car* sportsCarWithLeatherSeats = new LeatherSeats(sportsCarWithSunroof);  // Add leather seats decorator
    sportsCarWithLeatherSeats->assemble();  // Assemble car with both sunroof and leather seats

    // Clean up
    delete sportsCarWithLeatherSeats;
    delete sportsCarWithSunroof;
    delete sportsCar;

    return 0;
}


/*
OUTPUT:

Assembling Sports Car: 
Basic Car.

Assembling Sports Car with Sunroof: 
Basic Car.
Adding Sunroof.

Assembling Sports Car with Sunroof and Leather Seats: 
Basic Car.
Adding Sunroof.
Adding Leather Seats.

*/

