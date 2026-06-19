#include <iostream>

//Abstract Product
class Animal{
public:
	virtual void speak() = 0;
	virtual ~Animal() = default;
};

//Concrete Product - Dog
class Dog:public Animal{
public:
	void speak() override {
		std::cout<<"Woof!"<<std::endl;
	}
};

//Concrete Product - Cat
class Cat:public Animal{
public:
	void speak() override {
		std::cout<<"Meow!"<<std::endl;
	}
};

//Abstract Factory
class AnimalFactory{
public:
	virtual Animal* createAnimal() = 0;
	virtual ~AnimalFactory() = default;
};

//Concrete Factory - DogFactory
class DogFactory: public AnimalFactory{
public:
	Animal* createAnimal() override {
		return new Dog();
	}
};

//Concrete Factory - CatFactory
class CatFactory: public AnimalFactory{
public:
	Animal* createAnimal() override {
		return new Cat();
	}
};

int main(){
	AnimalFactory* dogFactory = new DogFactory();
	Animal* dog = dogFactory->createAnimal();
	dog->speak();

	AnimalFactory* catFactory = new CatFactory();
	Animal* cat = catFactory->createAnimal();
	cat->speak();


	delete dog;
	delete dogFactory;
	delete cat;
	delete catFactory;

	return 0;
}


/*

Woof!
Meow!

*/




