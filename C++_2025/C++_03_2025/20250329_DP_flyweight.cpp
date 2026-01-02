// Step 1: Define the Flyweight Interface
#include <iostream>
#include <unordered_map>
#include <string>

// Flyweight Interface
class TreeType {
public:
    virtual void draw(int x, int y) = 0;  // Draw the tree at a specific position
    virtual ~TreeType() = default;
};


// Step 2: Define Concrete Flyweight
// Concrete Flyweight - TreeType (shared data)
class TreeTypeImpl : public TreeType {
private:
    std::string name;  // Intrinsic state: Type of tree (e.g., Oak, Pine)

public:
    TreeTypeImpl(const std::string& name) : name(name) {}

    void draw(int x, int y) override {
        std::cout << "Drawing " << name << " at position (" << x << ", " << y << ")" << std::endl;
    }
};


// Step 3: Define the Flyweight Factory
// Flyweight Factory
class TreeTypeFactory {
private:
    std::unordered_map<std::string, TreeType*> treeTypes;

public:
    TreeType* getTreeType(const std::string& name) {
        // Check if the tree type already exists in the map
        if (treeTypes.find(name) == treeTypes.end()) {
            treeTypes[name] = new TreeTypeImpl(name);  // Create a new tree type if not found
        }
        return treeTypes[name];
    }

    ~TreeTypeFactory() {
        // Clean up all the tree types created by the factory
        for (auto& pair : treeTypes) {
            delete pair.second;
        }
    }
};


// Step 4: Define the Client Code
// Client code
int main() {
    TreeTypeFactory treeFactory;  // Flyweight Factory

    // Create many trees with the same type but different positions
    TreeType* oak = treeFactory.getTreeType("Oak");
    oak->draw(10, 20);
    oak->draw(30, 40);

    TreeType* pine = treeFactory.getTreeType("Pine");
    pine->draw(50, 60);
    pine->draw(70, 80);

    TreeType* oak2 = treeFactory.getTreeType("Oak");
    oak2->draw(90, 100);

    // Output will show shared "Oak" tree type and different positions
    // Drawing Oak at position (10, 20)
    // Drawing Oak at position (30, 40)
    // Drawing Pine at position (50, 60)
    // Drawing Pine at position (70, 80)
    // Drawing Oak at position (90, 100)

    return 0;
}


/*
OUTPUT:

Drawing Oak at position (10, 20)
Drawing Oak at position (30, 40)
Drawing Pine at position (50, 60)
Drawing Pine at position (70, 80)
Drawing Oak at position (90, 100)

*/