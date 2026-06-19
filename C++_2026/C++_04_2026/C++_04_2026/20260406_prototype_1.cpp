#include <iostream>
#include <string>

//Prototype Class
class Shape{
public:
	virtual Shape* clone() const = 0;
	virtual void draw() const = 0;
	virtual ~Shape() = default;
};

//Concrete Prototype - Circle
class Circle: public Shape{
private:
	std::string color;
public:
	Circle(std::string clr):color(clr){}

	Shape* clone() const override {
		return new Circle(*this);
	}

	void draw() const override {
		std::cout<<"Drawing Circle with color: "<<color<<std::endl;
	}
};

//Concrete Prototype - Rectangle
class Rectangle: public Shape{
private:
	std::string color;
public:
	Rectangle(std::string clr): color(clr){}

	Shape* clone() const override {
		return new Rectangle(*this);
	}

	void draw() const override {
		std::cout<<"Drawing Rectangle with Color: "<<color<<std::endl;
	}
};

int main(){
	Shape* originalCircle = new Circle("Red");
	Shape* originalRectangle = new Rectangle("Blue");

	Shape* clonedCircle = originalCircle->clone();
	Shape* clonedRectangle = originalRectangle->clone();

	originalCircle->draw();
	clonedCircle->draw();
	originalRectangle->draw();
	clonedRectangle->draw();


	delete originalCircle;
	delete originalRectangle;
	delete clonedCircle;
	delete clonedRectangle;

	return 0;
}

