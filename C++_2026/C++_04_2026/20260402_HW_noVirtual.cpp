#include <iostream>

class Base{
public:
	void show(){
		std::cout<<"Base Message"<<std::endl;
	}
};

class Derived: public Base{
public:
	void show(){
		std::cout<<"Derived Message"<<std::endl;
	}
};

int main(){
Base* ptr;
Base b1;
ptr = &b1;
ptr->show();

Derived d1;
ptr = &d1;
ptr->show();

return 0;
}

