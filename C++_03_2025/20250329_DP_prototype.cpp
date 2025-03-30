// Step 1: Define the Prototype Interface
#include <iostream>
#include <string>

// Prototype class
class Shape {
public:
    virtual Shape* clone() const = 0; // Clone method
    virtual void draw() const = 0; // Method to display the shape
    virtual ~Shape() = default;
};


// Step 2: Define Concrete Prototypes
// ConcretePrototype - Circle
class Circle : public Shape {
private:
    std::string color;
public:
    Circle(std::string color) : color(color) {}

    Shape* clone() const override {
        return new Circle(*this); // Copy the current object
    }

    void draw() const override {
        std::cout << "Drawing Circle with color: " << color << std::endl;
    }
};

// ConcretePrototype - Rectangle
class Rectangle : public Shape {
private:
    std::string color;
public:
    Rectangle(std::string color) : color(color) {}

    Shape* clone() const override {
        return new Rectangle(*this); // Copy the current object
    }

    void draw() const override {
        std::cout << "Drawing Rectangle with color: " << color << std::endl;
    }
};


// Step 3: Client Code
int main() {
    // Create a prototype circle and rectangle
    Shape* originalCircle = new Circle("Red");
    Shape* originalRectangle = new Rectangle("Blue");

    // Clone the original objects
    Shape* clonedCircle = originalCircle->clone();
    Shape* clonedRectangle = originalRectangle->clone();

    // Draw the original and cloned objects
    originalCircle->draw();  // Output: Drawing Circle with color: Red
    clonedCircle->draw();    // Output: Drawing Circle with color: Red

    originalRectangle->draw();  // Output: Drawing Rectangle with color: Blue
    clonedRectangle->draw();    // Output: Drawing Rectangle with color: Blue

    // Clean up
    delete originalCircle;
    delete originalRectangle;
    delete clonedCircle;
    delete clonedRectangle;

    return 0;
}


/*
OUTPUT:

Drawing Circle with color: Red
Drawing Circle with color: Red
Drawing Rectangle with color: Blue
Drawing Rectangle with color: Blue

*/





