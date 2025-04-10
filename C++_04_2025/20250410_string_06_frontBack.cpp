#include <iostream>
#include <string>

using namespace std;

int main()
{
string str = "Hello";
cout<<str.front()<<endl;
cout<<str.back()<<endl;

cout<<str.at(0)<<endl;
cout<<str.at(2)<<endl;

for(int i=0; i<str.size(); i++){
    cout<<str.at(i);
}
cout<<endl;

cout<<str.data()<<endl;
return 0;
}

/*
Output:

H
o
H
l
Hello
Hello

*/