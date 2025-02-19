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

    friend void friendFunction(Shape &b);

};

void friendFunction(Shape &b)
{

    cout<<"Area: "<<b.length * b.breadth<<endl;
}

int main()
{
Shape b1(3,4);
Shape *ptr2 = new Shape(5,6);
friendFunction(*ptr2);
return 0;
}

