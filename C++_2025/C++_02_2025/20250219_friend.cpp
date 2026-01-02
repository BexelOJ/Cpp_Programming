#include <iostream>
using namespace std;

class Shape{

private:
    int length;
    int breadth;

public:
    Shape(int l, int b):length(l),breadth(b)
    {
        cout<<"Base Class Parameterized Construtor Called"<<endl;
    }

    friend void friendFunction(Shape &b);  // friend function declaration

};

void friendFunction(Shape &b)  // friend function definition
{

    cout<<"Area: "<<b.length * b.breadth<<endl;
}

int main()
{
Shape b1(3,4);      // one object in stack
Shape *ptr2 = new Shape(5,6);  // another object in heap
friendFunction(b1);    // passing object 1
friendFunction(*ptr2);  // passing object 2
return 0;
}

