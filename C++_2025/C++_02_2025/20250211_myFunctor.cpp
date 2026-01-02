#include <iostream>

using namespace std;

class Myclass
{
    private:
        int value;
    public:
int operator()(int v)//:value(v)
{
    cout<<"Function Object called with value : "<<v<<endl;
    cout<<v<<" * "<<v<<" is : ";
    return v*v;
}
};


int main()
{
int a;
cout<<"Enter a value: "<<endl;
cin>>a;
Myclass m1;
cout<<m1.operator()(a)<<endl; 

return 0;
}


