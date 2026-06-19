#include <iostream>

class Singleton{
static Singleton* Instance;
Singleton(){};
public:
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
	static Singleton* getInstance(){
		if(Instance == nullptr){
			Instance = new Singleton();
		}
		return Instance;
	}
	void showMessage(){
		std::cout<<"Message Shown"<<std::endl;
	}

};

Singleton* Singleton::Instance = nullptr;

int main(){
	Singleton* s1 = Singleton::getInstance();
	s1->showMessage();

	Singleton* s2 = Singleton::getInstance();
	s2->showMessage();

	bool r = (s1 == s2)? true: false;
	std::cout<<"Same Instance ? : "<<r<<std::endl;
	return 0;
}


