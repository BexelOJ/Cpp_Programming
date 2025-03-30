// Step 1: Define the Product
#include <iostream>
#include <string>

// Product class
class Computer {
public:
    std::string cpu;
    std::string ram;
    std::string storage;

    void show() {
        std::cout << "Computer Specifications:\n";
        std::cout << "CPU: " << cpu << "\n";
        std::cout << "RAM: " << ram << "\n";
        std::cout << "Storage: " << storage << "\n";
    }
};


// Step 2: Define the Builder Interface
// Abstract builder class
class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer* getResult() = 0;
    virtual ~ComputerBuilder() = default;
};


// Step 3: Define Concrete Builders
// Concrete builder class for a gaming computer
class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;
public:
    GamingComputerBuilder() {
        computer = new Computer();
    }

    void buildCPU() override {
        computer->cpu = "Intel Core i9";
    }

    void buildRAM() override {
        computer->ram = "32GB DDR4";
    }

    void buildStorage() override {
        computer->storage = "1TB SSD";
    }

    Computer* getResult() override {
        return computer;
    }
};

// Concrete builder class for an office computer
class OfficeComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;
public:
    OfficeComputerBuilder() {
        computer = new Computer();
    }

    void buildCPU() override {
        computer->cpu = "Intel Core i5";
    }

    void buildRAM() override {
        computer->ram = "8GB DDR4";
    }

    void buildStorage() override {
        computer->storage = "500GB HDD";
    }

    Computer* getResult() override {
        return computer;
    }
};


// Step 4: Define the Director
// Director class
class Director {
private:
    ComputerBuilder* builder;
public:
    void setBuilder(ComputerBuilder* newBuilder) {
        builder = newBuilder;
    }

    Computer* constructComputer() {
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        return builder->getResult();
    }
};


// Step 5: Using the Builder in the Client Code
int main() {
    // Create the director
    Director director;

    // Create and set the builder for a gaming computer
    GamingComputerBuilder gamingBuilder;
    director.setBuilder(&gamingBuilder);

    // Construct the gaming computer
    Computer* gamingPC = director.constructComputer();
    gamingPC->show();  // Output: Specifications of a gaming computer

    std::cout << "\n";

    // Create and set the builder for an office computer
    OfficeComputerBuilder officeBuilder;
    director.setBuilder(&officeBuilder);

    // Construct the office computer
    Computer* officePC = director.constructComputer();
    officePC->show();  // Output: Specifications of an office computer

    // Cleanup
    delete gamingPC;
    delete officePC;

    return 0;
}


/*
OUTPUT:
Computer Specifications:
CPU: Intel Core i9
RAM: 32GB DDR4
Storage: 1TB SSD

Computer Specifications:
CPU: Intel Core i5
RAM: 8GB DDR4
Storage: 500GB HDD

*/