#include <iostream>
using namespace std;

class vehicle {
public:
    virtual void sound() 
    { 
        cout << "Vehicle sound" << endl; 
    }
    virtual ~vehicle() {}
};

class car : public vehicle 
{
public:
    void sound() override { 
        cout <<endl<<"Car sound" << endl<<endl; 
    }
};

class bike : public vehicle 
{
public:
    void sound() override { 
        cout <<endl<<"Bike sound" << endl<<endl; 
    }
};

int main() {
    vehicle* v;  // Base class pointer

    int choice=0;
    cout << "Enter "<<endl<<"1.) for Car "<<endl<<"       or "<<endl<<"2.) for Bike"<<endl;
    cin >> choice;

    // Decide which object to create based on user input
    if (choice == 1) 
    {
        v = new car();  // Create a car object dynamically
    } 

    else if (choice == 2) 
    {
        v = new bike();  // Create a bike object dynamically
    } 
    
    else 
    {
        cout << endl<<"Invalid choice!" << endl;
        return 0;
    }

    // Call sound() - which will be dynamically dispatched based on the object type
    v->sound();  // This will call car::sound() or bike::sound() depending on the user choice

    delete v;  // Cleanup

    return 0;
}
