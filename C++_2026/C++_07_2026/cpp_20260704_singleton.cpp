#include <iostream>

class Singleton {
 static Singleton* instance;
   Singleton() {
    std::cout << "Singleton instance created." << std::endl;
  }
public:
  static Singleton* stance(){
   if(instance == nullptr){
     instance = new Singleton();
   }
   return instance;
  }

};

Singleton* Singleton::instance = nullptr;

int main(){
   Singleton* singleton_1 = Singleton::getinstance();
   Singleton* singleton_2 = Singleton::getinstance();
   if(singleton_1 == singleton_2){
       std::cout << "Both instances are the same." << std::endl;
   }

   return 0;
}


