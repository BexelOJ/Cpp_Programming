#include <iostream>

class Singleton{
static Singleton* instance;
Singleton(){
   std::cout<<"Singleton instance created"<<std::endl;
}
public:
static Singleton* InstanceFunction(){
   if(instance == nullptr){
      instance = new Singleton();
   }
   return instance;
}

};

Singleton* Singleton::instance = nullptr;

int main(){
Singleton* s1 = Singleton::InstanceFunction();
Singleton* s2 = Singleton::InstanceFunction();

if (s1 == s2){
   
   std::cout<<"Both instances are the same"<<std::endl;
}
return 0;
}


