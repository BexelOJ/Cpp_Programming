#include <iostream>
#include <string>

using namespace std;

int main()
{
string str = "Manu Kumar";
string str2 = " Yadav";

cout<<str<<endl;
size_t size = str.size();
size_t len = str.length();
size_t maxSize = str.max_size();

cout<<"Size of the String : "<<size<<endl;
cout<<"Length of the String : "<<len<<endl;
cout<<"Max Size of the String : "<<maxSize<<endl;

str.resize(15,'c');
cout<<"resized the String : "<<str.size()<<endl;
cout<<"New String : "<<str<<endl;
cout<<"Capacity of String : "<<str.capacity()<<endl;
string str3 =  str+str2;
cout<<str3<<endl;


return 0;
}


/*
Output:

Manu Kumar
Size of the String : 10
Length of the String : 10
Max Size of the String : 4611686018427387903
resized the String : 15
New String : Manu Kumarccccc
Capacity of String : 15
Manu Kumarccccc Yadav

*/