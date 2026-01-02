// Step 1: Define the Target Interface
#include <iostream>

// Target Interface
class ModernSystem {
public:
    virtual void connect() = 0; // Expected interface
    virtual ~ModernSystem() = default;
};


// Step 2: Define the Adaptee (Incompatible Class)
// Adaptee with an incompatible interface
class LegacySystem {
public:
    void establishConnection() {
        std::cout << "Legacy System: Connection established!" << std::endl;
    }
};


// Step 3: Define the Adapter
// Adapter class
class LegacyToModernAdapter : public ModernSystem {
private:
    LegacySystem* legacySystem; // Contains an instance of the adaptee

public:
    LegacyToModernAdapter(LegacySystem* system) : legacySystem(system) {}

    void connect() override {
        std::cout << "Adapter: Adapting legacy system's connection method..." << std::endl;
        legacySystem->establishConnection(); // Delegate the call to the legacy system
    }

    ~LegacyToModernAdapter() {
        delete legacySystem;
    }
};


// Step 4: Client Code
int main() {
    // The client only knows about the modern interface
    ModernSystem* modernSystem = new LegacyToModernAdapter(new LegacySystem());

    modernSystem->connect();  // Adapter will delegate the call to LegacySystem

    // Clean up
    delete modernSystem;
    return 0;
}


/*
OUTPUT:
Adapter: Adapting legacy system's connection method...
Legacy System: Connection established!

*/
