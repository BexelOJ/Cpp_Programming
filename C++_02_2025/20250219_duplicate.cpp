#include <iostream>
using namespace std;

void duplicate(int &x, int &y, int &z)
{
    x *= 2;
    y *= 2;
    z *= 2;
}

int main()
{
int a=1, b=2, c=3;
duplicate(a,b,c);
cout<<a<<" "<<b<<" "<<c<<endl;
return 0;
}

