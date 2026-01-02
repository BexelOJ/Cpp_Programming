#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
char str[] = "Alice is in wonderland, Always Has Been";
int n = strlen(str);
int m = sizeof(str);
cout<<n<<" "<<m<<endl;

for(int i=0; i<n; i++)
{ 
    if(str[i] == 73)
    {
        cout<<"Correct"<<endl;
        str[i] = str[108];
        break;
    }
    else
    {
        cout<<"Not correct"<<endl;
    }
}

for(int j=65; j<90; j++)
{
   // cout<<j<<endl;
    printf("%x",j);
}

cout<<str<<endl;
return 0;
}

