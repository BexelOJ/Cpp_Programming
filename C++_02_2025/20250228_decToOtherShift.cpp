#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
int n=0, s=0, num;
cout<<"Enter a Decimal Number: "<<endl;
cin>>n;
s=sizeof(n)*8;
cout<<s<<endl;
for(int i=0; i<s; i++)
{
    num = n>>(s-i-1);
    if(num%2)
        cout<<1;
    else
        cout<<0;
}
cout<<endl;
return 0;
}

/*

00000000000000000000000000001100  // for 12

00000000000000000000000001001110  // for 78

*/