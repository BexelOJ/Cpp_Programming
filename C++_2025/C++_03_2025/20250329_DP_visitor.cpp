// Step 1: Define the Visitor Interface
#include <iostream>
#include <cmath>

// Forward declarations of ConcreteElements
class Circle;
class Rectangle;

// Visitor Interface
class ShapeVisitor {
public:
    virtual void visitCircle(Circle* circle) = 0;
    virtual void visitRectangle(Rectangle* rectangle) = 0;
    virtual ~ShapeVisitor() = default;
};


// Step 2: Define the Element Interface
// Element Interface
class Shape {
public:
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual ~Shape() = default;
};


// Step 3: Create ConcreteElement Classes
// Circle Class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const { return radius; }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCircle(this);
    }
};

// Rectangle Class
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitRectangle(this);
    }
};


// Step 4: Create Concrete Visitor Classes
class AreaCalculator : public ShapeVisitor {
public:
    void visitCircle(Circle* circle) override {
        double area = M_PI * circle->getRadius() * circle->getRadius();
        std::cout << "Area of Circle: " << area << std::endl;
    }

    void visitRectangle(Rectangle* rectangle) override {
        double area = rectangle->getWidth() * rectangle->getHeight();
        std::cout << "Area of Rectangle: " << area << std::endl;
    }
};


// Concrete Visitor: Drawer
class Drawer : public ShapeVisitor {
public:
    void visitCircle(Circle* circle) override {
        std::cout << "Drawing Circle with radius " << circle->getRadius() << std::endl;
    }

    void visitRectangle(Rectangle* rectangle) override {
        std::cout << "Drawing Rectangle with width " << rectangle->getWidth() 
                  << " and height " << rectangle->getHeight() << std::endl;
    }
};


// Step 5: Client Code
int main() {
    // Create shapes
    Shape* circle = new Circle(5);
    Shape* rectangle = new Rectangle(4, 6);

    // Create visitors
    ShapeVisitor* areaCalculator = new AreaCalculator();
    ShapeVisitor* drawer = new Drawer();

    // Accept visitors and perform operations
    circle->accept(areaCalculator);
    rectangle->accept(areaCalculator);

    circle->accept(drawer);
    rectangle->accept(drawer);

    // Clean up
    delete circle;
    delete rectangle;
    delete areaCalculator;
    delete drawer;

    return 0;
}


/*
OUTPUT:

Area of Circle: 78.5398
Area of Rectangle: 24
Drawing Circle with radius 5
Drawing Rectangle with width 4 and height 6

*/