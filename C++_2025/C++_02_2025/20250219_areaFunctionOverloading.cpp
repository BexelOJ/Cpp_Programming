#include <iostream>
using namespace std;

class Shape{

    public:
    double r=0;
    int l=0, b=0;
    double Area(double r)  // Circle
    {
        return (3.14 * r * r);
    }

    int Area(int l)  // Square
    {
        return (l * l);
    }

    int Area(int l, int b)  // Rectangle
    {
        return (l * b);
    }

};

int main()
{
Shape c1, s1, r1;
cout<<"Area of Circle: "<<c1.Area(3.0)<<endl;
cout<<"Area of Square: "<<s1.Area(4)<<endl;
cout<<"Area of Rectangle: "<<r1.Area(2,4)<<endl;
//Area c1
return 0;
}






