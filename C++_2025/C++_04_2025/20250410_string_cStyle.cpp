#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
const char* str = "Hello";
string str2 = "World";
const char* str3 = str2.c_str();

int s = sizeof(str);
cout<<"String: "<<str<<endl;
cout<<"Size "<<s<<endl;
cout<<"Char "<<str[0]<<endl;
cout<<"Size of String: "<<str2.size()<<endl;
cout<<"Size C Style: "<<strlen(str3)<<endl;

for(int i=0; i<str2.size(); i++)
{
    cout<<str2[i];
    if(str[i] == '\0')
        break;
}
cout<<endl;

for(int i=0; i<s; i++)
{
    cout<<str[i];
    if(str[i] == '\0')
        break;
}
cout<<endl;

return 0;
}

/*
Output:

String: Hello
Size 8
Char H
Size of String: 5
Size C Style: 5
World
Hello

*/