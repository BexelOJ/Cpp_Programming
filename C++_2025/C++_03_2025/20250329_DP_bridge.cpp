// Step 1: Define the Implementor Interface
#include <iostream>
#include <string>

// Implementor interface
class Color {
public:
    virtual void fillColor() = 0; // A method to fill color
    virtual ~Color() = default;
};


// Step 2: Define Concrete Implementors
// ConcreteImplementor - Red color
class RedColor : public Color {
public:
    void fillColor() override {
        std::cout << "Filling with Red Color!" << std::endl;
    }
};

// ConcreteImplementor - Blue color
class BlueColor : public Color {
public:
    void fillColor() override {
        std::cout << "Filling with Blue Color!" << std::endl;
    }
};


// Step 3: Define the Abstraction
// Abstraction
class Shape {
protected:
    Color* color; // Reference to Implementor

public:
    Shape(Color* color) : color(color) {}

    virtual void draw() = 0; // Abstract method to draw the shape
    virtual void applyColor() {
        color->fillColor(); // Delegate the filling operation to the color
    }

    virtual ~Shape() = default;
};


// Step 4: Define Refined Abstractions
// Refined Abstraction - Circle
class Circle : public Shape {
public:
    Circle(Color* color) : Shape(color) {}

    void draw() override {
        std::cout << "Drawing a Circle!" << std::endl;
    }
};

// Refined Abstraction - Square
class Square : public Shape {
public:
    Square(Color* color) : Shape(color) {}

    void draw() override {
        std::cout << "Drawing a Square!" << std::endl;
    }
};

// Step 5: Client Code
int main() {
    // Create color objects
    Color* red = new RedColor();
    Color* blue = new BlueColor();

    // Create shapes with different colors
    Shape* redCircle = new Circle(red);
    Shape* blueSquare = new Square(blue);

    // Draw the shapes and apply color
    redCircle->draw();
    redCircle->applyColor();  // Fill with Red

    blueSquare->draw();
    blueSquare->applyColor();  // Fill with Blue

    // Clean up
    delete red;
    delete blue;
    delete redCircle;
    delete blueSquare;

    return 0;
}


/*
OUTPUT:

Drawing a Circle!
Filling with Red Color!
Drawing a Square!
Filling with Blue Color!

*/