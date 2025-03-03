#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
char str1[100];
char str2[] = "Hello World";

cout<<"Enter a String:"<<endl;
cin.getline(str1, 100);

int s1 = strlen(str1);
int s2 = strlen(str2);

cout<<s1<<endl<<s2<<endl;

for(int i=0; i<s2; i++)
{
  if(str2[i] >= 'a' && str2[i] <='z')
  {
    str2[i] = str2[i] - 32;
  }

}

for(int i=0; i<s1; i++)
{
  if(str1[i] >= 'a' && str1[i] <='z')
  {
    str1[i] = str1[i] - 32;
  }

}
cout<<str1<<endl;
cout<<str2<<endl;
return 0;
}

/*

Hello India New India
21
11
HELLO INDIA NEW INDIA
HELLO WORLD

*/

