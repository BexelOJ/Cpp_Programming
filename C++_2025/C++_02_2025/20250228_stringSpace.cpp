#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
string str1 = "Alice is always in wonderland";
char str2[] = "All people are not like alice ";
int n=0, m=0, count1=0, count2=0;
cout<<str1<<endl;
cout<<str2<<endl;
n = str1.size();
m = strlen(str2);
for(int i=0; i<n; i++)
{
    if(str1[i] == ' ')// | str[i] == '\0')
    {
        count1++;
    }
}
for(int i=0; i<m; i++)
{
    if(str2[i] == ' ')// | str[i] == '\0')
    {
        count2++;
    }
}
cout<<"Number of spaces in string 1: "<<count1<<endl;
cout<<"Number of spaces in string 2: "<<count2<<endl;

printf("%d\n",str1[0]);
printf("%x\n",str1[0]);
printf("%b\n",str1[0]);

return 0;
}

/*

Alice is always in wonderland
All people are not like alice 
Number of spaces in string 1: 4
Number of spaces in string 2: 6
65
41
1000001

*/


