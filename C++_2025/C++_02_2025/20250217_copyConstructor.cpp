#include <iostream>

using namespace std;

class Base{
private:
    int a;
    int b;
public: 
    int c;
    
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
b1.Display();

Base b2 = b1;
b2.Display();

Base *b3 = new Base(3,4);
b3->Display();

Base *b4 = b3;
b4->Display(); 
return 0;
}

/*
Base Constructor Called
Inside Base Class
1 and 2
Inside Base Class
1 and 2
Base Constructor Called
Inside Base Class
3 and 4
Inside Base Class
3 and 4
*/

