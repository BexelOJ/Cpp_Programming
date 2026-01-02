#include <iostream>
using namespace std;

class Base{
public:
    virtual void show(){
        cout<<"In Base Class Show function"<<endl;
    }
    /*
    void show(){  // without virtual, this will not allow dynamic binding
        cout<<"In Base Class Show function"<<endl;
    }
    */
    virtual ~Base(){};
};

class Derived: public Base{
public:
    void show(){
        cout<<"In Derived Class Show function"<<endl;
    }    
};

int main(){

Base* b1 = new Base(); // possible
b1->show();

Derived* d1 = new Derived(); // possible
d1->show();

// Derived* d2 = new Base(); // error: cannot convert Base* to Derived*
// d2->show(); // this line will not compile

 Base* b2 = new Base();  // dynamic_cast failed
 b2->show(); 
 Derived* d2 = dynamic_cast<Derived*>(b2); 
   if (d2)
      d2->show();
   else
      cout << "dynamic_cast failed (for d2)" << endl;


Base* b3 = new Derived();  // upcasting 
b3->show();

Derived* d3 = dynamic_cast<Derived*>(b3);  // downcasting
if (d3)  // check if downcast was successful
    d3->show();
else
    cout << "dynamic_cast failed (for d3)" << endl;
    
return 0;    
}

/*

Output: (without virtual in Base class show())
In Base Class Show function
In Derived Class Show function
In Base Class Show function
In Derived Class Show function

Output: (with virtual in Base class show())
In Base Class Show function
In Derived Class Show function
In Derived Class Show function
In Derived Class Show function

*/