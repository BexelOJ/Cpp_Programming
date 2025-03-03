
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
  if(str2[i] >= 'A' && str2[i] <='Z')
  {
    str2[i] = str2[i] + 32;
  }

}

for(int i=0; i<s1; i++)
{
  if(str1[i] >= 'A' && str1[i] <='Z')
  {
    str1[i] = str1[i] + 32;
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
hello india new india
hello world

*/

