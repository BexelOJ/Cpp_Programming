#include <iostream>

class Base{
   static int a;  // first static variable
public:
   static int getA() { // getter function to access the private variable
      return a; 
   }   
   static int b;  // second static variable
};

class Derived{
   static int a;  // third static variable
public:
   static int getA() { // getter function to access the private variable
      return a; 
   }
   static int b;  // fourth static variable
};

int Base::a = 10;
int Base::b = 20;
int Derived::a = 30;
int Derived::b = 40;

int main(){
   Base* b1 = new Base();
   Derived* d1 = new Derived();

   std::cout<<"Static a: "<<Base::getA()<<std::endl;
   std::cout<<"Static b: "<<Base::b<<std::endl;
   std::cout<<"Static c: "<<Derived::getA()<<std::endl;     
   std::cout<<"Static d: "<<Derived::b<<std::endl;

   std::cout<<"Size of Base: "<<sizeof(*b1)<<std::endl;
   std::cout<<"Size of Derived: "<<sizeof(*d1)<<std::endl;

   std::cout<<b1->getA()<<std::endl;
   std::cout<<b1->b<<std::endl;
   std::cout<<d1->getA()<<std::endl;
   std::cout<<d1->b<<std::endl;

   return 0;
}


