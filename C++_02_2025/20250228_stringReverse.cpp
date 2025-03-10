#include <iostream>
#include <cstring>

int n=0;

using namespace std;

void reverse(int x, char strg[])
{
    for(int i=x,j=0; i>=0,j<x; i--,j++)
    {
        //cout<<strg[i];
        strg[j] = strg[i];
    }
//cout<<strg<<endl;
for(int i=0; i<x; i++)
    {
        cout<<strg[i];
    }
cout<<endl;
//return strg[];
}

int main()
{
string str = "Hello World!";
char str2[] = "Alice is still in wonderland";

cout<<str<<endl;
n = strlen(str2);
for(int i=0; i<n; i++)
    {
        cout<<str2[i];
    }
cout<<endl;

//char res[] = 
reverse(n,str2);
//cout<<res<<endl;
return 0;
}

/*

Hello World!
Alice is still in wonderland
dnalrednow ni in wonderland

*/


