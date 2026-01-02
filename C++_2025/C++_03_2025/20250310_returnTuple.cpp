#include <iostream>
#include <tuple>

using namespace std;

class Base
{
    int a;
    int b;
    char c;
public:
    
    Base(int x, int y, char z):a(x), b(y), c(z){
        cout<<"PC Called"<<endl;
    }
    tuple<int, int, char> show()
    {
        return make_tuple(a, b, c);
    }

    friend void display(const Base &b);
};

void display(const Base &other)
{
    cout<< other.a <<" "<< other.b <<" "<< other.c<<endl;
}

int main()
{
Base b1(10,20,'c');
Base *ptr = new Base(30,40,'f');

display(b1);

tuple<int ,int, char> res = ptr->show();

int l=0;
int m=0;
char n;

tie(l, m, n) = res;
cout<<l<<" "<<m<<" "<<n<<endl;
return 0;
}



