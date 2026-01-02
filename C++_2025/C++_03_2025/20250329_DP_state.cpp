// 1. State Interface (Abstract Class)
// The VendingMachineState interface will declare methods that the concrete states must implement.
#include <iostream>
#include <memory>

// State interface
class VendingMachineState {
public:
    virtual void insertMoney() = 0;
    virtual void ejectMoney() = 0;
    virtual void selectProduct() = 0;
    virtual void dispenseProduct() = 0;
    virtual ~VendingMachineState() {}
};


//2. Concrete States
//Each state(Idle, HasMoney, SoldOut) will implement the state - specific behavior.
//
//Idle State :
//This is the initial state where no money has been inserted.
class IdleState : public VendingMachineState {
public:
    void insertMoney() override {
        std::cout << "Money inserted. You can select a product now." << std::endl;
    }

    void ejectMoney() override {
        std::cout << "No money to eject." << std::endl;
    }

    void selectProduct() override {
        std::cout << "Insert money first!" << std::endl;
    }

    void dispenseProduct() override {
        std::cout << "You need to insert money and select a product first." << std::endl;
    }
};


//HasMoney State :
//This state indicates that the machine has money, and the user can select a product.
class HasMoneyState : public VendingMachineState {
public:
    void insertMoney() override {
        std::cout << "Money already inserted. Select a product." << std::endl;
    }

    void ejectMoney() override {
        std::cout << "Money ejected. You can insert money again." << std::endl;
    }

    void selectProduct() override {
        std::cout << "Product selected. Dispensing product." << std::endl;
    }

    void dispenseProduct() override {
        std::cout << "Dispensing the product now." << std::endl;
    }
};

//SoldOut State :
//This state occurs when the machine is out of stock.
class SoldOutState : public VendingMachineState {
public:
    void insertMoney() override {
        std::cout << "Machine is out of stock. Can't accept money." << std::endl;
    }

    void ejectMoney() override {
        std::cout << "No money to eject." << std::endl;
    }

    void selectProduct() override {
        std::cout << "Product sold out. Cannot select a product." << std::endl;
    }

    void dispenseProduct() override {
        std::cout << "Can't dispense product. Machine is sold out." << std::endl;
    }
};


//3. Context Class(Vending Machine)
//The VendingMachine class will hold the current state and delegate behavior to the state objects.
class VendingMachine {
private:
    VendingMachineState* currentState;
    VendingMachineState* idleState;
    VendingMachineState* hasMoneyState;
    VendingMachineState* soldOutState;

public:
    VendingMachine() {
        idleState = new IdleState();
        hasMoneyState = new HasMoneyState();
        soldOutState = new SoldOutState();
        currentState = idleState;  // Initial state is idle
    }

    void setState(VendingMachineState* state) {
        currentState = state;
    }

    void insertMoney() {
        currentState->insertMoney();
    }

    void ejectMoney() {
        currentState->ejectMoney();
    }

    void selectProduct() {
        currentState->selectProduct();
    }

    void dispenseProduct() {
        currentState->dispenseProduct();
    }

    ~VendingMachine() {
        delete idleState;
        delete hasMoneyState;
        delete soldOutState;
    }
};

//4. Client Code
//The client code interacts with the VendingMachine class and its states.
int main() {
    VendingMachine machine;

    // Trying to insert money in the idle state
    machine.insertMoney();

    // Transition to has money state
    machine.setState(new HasMoneyState());
    machine.insertMoney();
    machine.selectProduct();
    machine.dispenseProduct();

    // Trying to select a product when the machine is out of stock
    machine.setState(new SoldOutState());
    machine.selectProduct();
    machine.insertMoney();

    return 0;
}











