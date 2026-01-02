#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
string str = "Hello World";
int s = str.length();
cout<<s<<endl;
for(int i=0; i<s; i++)
{
    cout<<str[i];
}
cout<<endl;
// reverse(str);
// for(int i=0; i<s; i++)
// {
//     cout<<str[i];
// }
// cout<<endl;
cout<<str.front()<<endl;
cout<<str.back()<<endl;
const char* ptr = str.data();
for(int i=0; i<s; i++)
{
    cout<<*(ptr +i);
}
cout<<endl;
str.erase();
str.clear();
str.assign("New India");
for(int i=0; i<s; i++)
{
    cout<<str[i];
}
cout<<endl;
return 0;
}





