// Addition of Two Complex Numbers with Operator Overloading

#include <iostream>

using namespace std;

class Complex{
    int real;
    int imag;
public:
    Complex(int r, int i):real(r),imag(i)  // Parameterized Constructor
    {

    }

void Add(const Complex &obj)  // Deep Copy
{
    real = real + obj.real;
    imag = imag + obj.imag;   
}
void display()  // getter function
{
    cout<<real<<" + "<<imag<<"i"<<endl;
}

};

int main()
{
int a,b,c,d;

cout<<"Enter Complex 1, Real and Imaginary part: "<<endl;
cin>>a>>b;
Complex c1(a,b);

cout<<"Enter Complex 2, Real and Imaginary part: "<<endl;
cin>>c>>d;
Complex c2(c,d);

c1.Add(c2); // to add Complex C1 and  Complex C2

c1.display();

return 0;    
}


