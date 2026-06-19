#include <iostream>
#include <string>

class Singleton{
	static Singleton* instance;
	Singleton(){
		std::cout<<"Constructor Called"<<std::endl;
	}
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* getInstance(){
		if(instance == nullptr){
			instance =  new Singleton();
		}
		return instance;
	}
	void showMessage(){
		std::cout<<"Message from Instance"<<std::endl;
	}
};

Singleton* Singleton::instance = nullptr;

int main(){
	Singleton* s1 = Singleton::getInstance();
	s1->showMessage();

	Singleton* s2 = Singleton::getInstance();
	s2->showMessage();

	bool same = (s1 == s2)? true : false ;

	if(same == true){
		std::cout<<"Both are same Instance"<<std::endl;
	}
	return 0;
}

/*

Constructor Called
Message from Instance
Message from Instance
Both are same Instance

*/

