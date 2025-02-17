#include <iostream>

using namespace std;

class Base{
private:
    int a = 10;
    int b = 20;
public: 
    int c = 30;
    Base(int x, int y):a(x), b(y){
        cout<<"Base Constructor Called"<<endl;
    }
    void Display()
    {
        cout<<"Inside Base Class"<<endl;
        cout<<a<<" and "<<b<<endl;
    }
};

int main()
{
Base b1(1,2);
Base b2 = b1;
b1.Display();
b2.Display();

Base *b3 = new Base(3,4);
b3->Display();
Base b4 = &b3;
b4->Display(); 
return 0;
}

