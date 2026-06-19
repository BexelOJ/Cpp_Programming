#include <iostream>

//Implementer Interface
class Color{
public:
	virtual void fillColor() = 0;
	virtual ~Color() = default;
};

//Concrete Implementer - Red Color
class RedColor: public Color{
public:
	void fillColor() override {
		std::cout<<"Filling with Red Color!"<<std::endl;
	}
};

//Concrete Implementer - Blue Color
class BlueColor: public Color{
public:
	void fillColor() override {
		std::cout<<"Filling with Blue Color!"<<std::endl;		
	}
};

class Shape{
protected:
	Color* color;
public:
	Shape(Color* color): color(color) {}
	virtual void draw() = 0;
	virtual void applyColor(){
		color->fillColor();
	}
	virtual ~Shape() = default;
};

class Circle: public Shape{
public:
	Circle(Color* color): Shape(color) {}
	void draw() override {
		std::cout<<"Drawing a Circle !"<<std::endl;
	}
};

class Square: public Shape{
public:
	Square(Color* color):Shape(color){}
	void draw() override {
		std::cout<<"Drawing a Square !"<<std::endl;
	}
};

int main(){
	Color* red = new RedColor();
	Color* blue = new BlueColor();

	Shape* redCirlce = new Circle(red);
	Shape* blueSquare = new Square(blue);

	redCirlce->draw();
	redCirlce->applyColor();

	blueSquare->draw();
	blueSquare->applyColor();

	delete red;
	delete blue;
	delete redCirlce;
	delete blueSquare;

	return 0;
}