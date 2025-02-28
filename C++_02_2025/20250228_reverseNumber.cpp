#include <iostream>

using namespace std;

int reverse(int m)
{
int temp=0, x=0;
for(;m>0;)
    {
        temp = m % 10; // 123 3 / 12 2
        m = m / 10;   // 12  1
        x = (x * 10) + temp;
    }
    return x; 
}

int main()
{
int n=0; 
cout<<"Enter a Number:"<<endl;
cin>>n;

cout<<reverse(n)<<endl;

return 0;
}





