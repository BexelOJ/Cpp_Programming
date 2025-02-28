#include <iostream>
#include <cstring>

int n=0;

using namespace std;

void reverse(int x, char strg[])
{
    for(int i=x; i>=0; i--)
    {
        cout<<strg[i];
    }
cout<<endl;
}

int main()
{
string str = "Hello World!";
char str2[] = "India is the best!";

cout<<str<<endl;
n = strlen(str2);
for(int i=0; i<n; i++)
    {
        cout<<str2[i];
    }
cout<<endl;

reverse(n,str2);

int 

return 0;
}


