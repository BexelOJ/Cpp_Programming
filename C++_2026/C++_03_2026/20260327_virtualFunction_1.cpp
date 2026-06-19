#include <iostream>

class Vehicle{
public:
    Vehicle() {
       // std::cout << "Vehicle Construtor Called" << std::endl;
    }

    virtual void sound() {
        std::cout << "\nVehicle Sound\n" << std::endl;
    }
};

class Car : public Vehicle{
public:
    Car() {
       // std::cout << "Car Construtor Called" << std::endl;
    }

    void sound() override {
        std::cout << "\nCar Sound\n" << std::endl;
    }
};

class Bus : public Vehicle {
public:
    Bus() {
        // std::cout << "Car Construtor Called" << std::endl;
    }

    void sound() override {
        std::cout << "\nBus Sound\n" << std::endl;
    }
};

class Bike : public Vehicle {
public:
    Bike() {
        // std::cout << "Car Construtor Called" << std::endl;
    }

    void sound() override {
        std::cout << "\nBike Sound\n" << std::endl;
    }
};

int main() {
    int n = 0;
    Vehicle* v1 = nullptr; // = new Vehicle();
    //Vehicle* v2 = new Car();

    while (true) {
        std::cout << "Enter the Number:\n\n" 
            << "1 for Vehicle Sound\n"
            << "2 for Car Sound\n"
            << "3 for Bus Sound\n"
            << "4 for Bike Sound\n\n"
            << "0 to Exit the Program\n\n"
            << "Enter Your Choise: ";
        
        std::cin >> n;
        
        if (n == 0) {
            std::cout << "Exiting ... " << std::endl;
            break;
        }

        //Clean Up, in each loop execution
        if (v1 != nullptr) {
            delete v1;
            v1 = nullptr;
        }

        if (n == 1) {
            v1 = new Vehicle();
        }

        else if (n == 2){
            v1 = new Car();
        }
        
        else if (n == 3) {
            v1 = new Bus();
        }

        else if (n == 4) {
            v1 = new Bike();
        }

        else {
            std::cout << "\nInvalid Input\n" << std::endl;
            continue;
        }
        
        v1->sound();
    }

    //Clean Up, while exiting
    if (v1 != nullptr) {
        delete v1;
    }

    return 0;
}


