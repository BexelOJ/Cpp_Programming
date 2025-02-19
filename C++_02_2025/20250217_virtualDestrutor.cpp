#include <iostream>

class Base {
public:
    Base() 
    { 
        std::cout << "Base class constructor\n"; 
    }
    
    virtual ~Base() 
    { 
        std::cout << "Base class destructor\n"; 
    } // Virtual destructor
};

class Derived : public Base {
public:
    Derived() 
    { 
        std::cout << "Derived class constructor\n"; 
    }
    ~Derived() 
    { 
        std::cout << "Derived class destructor\n"; 
    }
};

int main() 
{
    // Create a Derived object but delete it using a Base pointer
    Base* basePtr1 = new Base();
    Base* basePtr2 = new Derived();
    
    // When the object is deleted, both destructors should be called
    delete basePtr1;
    delete basePtr2;
    
    return 0;
}


/*
--------------------------------
Output:
--------------------------------
with Virtual Keyword:

Base class constructor     // for ptr1 base pointer
Base class constructor     // for ptr2 base pointer
Derived class constructor  // for ptr2 derived object
Base class destructor      // for ptr1 base pointer/object
Derived class destructor   // for ptr2 derived (object)
Base class destructor      // for ptr2 base (pointer)

--------------------------------
withour virtual keyword:

Base class constructor      // for ptr1 for base pointer
Base class constructor      // for ptr2 for base pointer
Derived class constructor   // for ptr2 for derived object
Base class destructor       // for ptr1 base pointer
Base class destructor       // for ptr2 base pointer

--------------------------------
*/

