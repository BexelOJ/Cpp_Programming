#include <iostream>
#include <cstring>

using namespace std;

int main()
{
char str[] = "110010101001";
int n=0, one=0, zero=0;
n= strlen(str);
for(int i=0;i<n;i++)
{
    if(str[i] == '1')
    {
        one++;
    }
    else
    {
     zero++;   
    }
}
cout<<"Number of One : "<<one<<endl;
cout<<"Number of Zero : "<<zero<<endl;
return 0;
}


/*

Number of One : 6
Number of Zero : 6

*/