#include <iostream>

using namespace std;

int main()
{
int n=0;
cout<<"Enter a Decimal Number: "<<endl;
cin>>n;
for(int i=31; i>=0; i--)
{
    cout<<((n>>i)&1);
}
cout<<endl;
return 0;
}

