#include <iostream>

//Abstract Product
class Animal{
public:
	virtual void speak() = 0; // pure virtual Function, makes this class abstract class
	virtual ~Animal() = default;
};

//Concrete Product - Dog
class Dog: public Animal{
public:
	void speak() override {
		std::cout<<"Dog says Woof!"<<std::endl;
	}
};

//Concrete Product - Cat
class Cat: public Animal{
public:
	void speak() override {
		std::cout<<"Cat says Meow!"<<std::endl;
	}
};

//Abstract Factory
class AnimalFactory{
public:
	virtual Animal* creatAnimal() = 0;
	virtual ~AnimalFactory() = default;
};

//Concrete factory - DogFactory
class DogFactory: public AnimalFactory{
public:
	 Animal* creatAnimal() override {
	 	return new Dog;
	}
};

//Concrete factory - CatFactory
class CatFactory: public AnimalFactory{
public:
	Animal* creatAnimal() override {
		return new Cat;
	}
};

int main(){
	AnimalFactory* dogFactory = new DogFactory();
	Animal* dog = dogFactory->creatAnimal();
	dog->speak();

	AnimalFactory* catFactory = new CatFactory();
	Animal* cat = catFactory->creatAnimal();
	cat->speak();

	return 0;
}





