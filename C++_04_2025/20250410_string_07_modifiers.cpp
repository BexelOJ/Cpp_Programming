#include <iostream>

using namespace std;

int main()
{
string str = "Hello ";
const char* s = "World";
str.append(s);
cout<<str<<endl;

string two = "New";
cout<<two<<endl;

two.assign("India");
cout<<two<<endl;

two.assign(str + " "+ s);
cout<<two<<endl;

two.push_back('I');
cout<<two<<endl;
two.pop_back();
cout<<two<<endl;
two.pop_back();
cout<<two<<endl;

string str2 = "Developing";
str2.insert(10," nation ");
cout<<str2<<endl;


string str3 = "Developing";
str3.insert(4," nation ");
cout<<str3<<endl;


return 0;
}

/*
Output:

Hello World
New
India
Hello World World
Hello World WorldI
Hello World World
Hello World Worl
Developing nation 
Deve nation loping

*/