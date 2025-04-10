#include <iostream>

using namespace std;

int main()
{
string str = "Hello ";
const char* s = "World";
str.append(s);
cout<<str<<endl;  
// Hello World

string two = "New";
cout<<two<<endl;  
// New

// *** assign() *** 
two.assign("India");
cout<<two<<endl;  
// India

two.assign(str + " "+ s);
cout<<two<<endl;  
// Hello World World

// *** push_back() *** 
two.push_back('I');
cout<<two<<endl;  
// Hello World WorldI

// *** pop_back() *** 
two.pop_back();
cout<<two<<endl; 
// Hello World World

two.pop_back();
cout<<two<<endl;  
// Hello World Worl

// *** insert() *** 
string str2 = "Developing";
str2.insert(10," nation ");
cout<<str2<<endl;  
// Developing nation
 
string str3 = "Developing";
str3.insert(4," nation ");
cout<<"Insert: "<<str3<<endl;  
// Insert: Deve nation loping

// *** erase() *** 
str2.erase(10, 8);  // (pos,number)
cout<<"Erase: "<<str2<<endl;  
// Erase: Developing

// *** replace() *** 
string str4 = "added";
str3.replace(4,4,str4);  // (pos, number, str)
cout<<"Replace: "<<str3<<endl;  
// Replace: Deveaddedion loping


// *** swap() *** 
string str6 = "Mc";
string str7 = "Donalds";
str6.swap(str7);
cout<<str6<<endl;  
// Donalds
cout<<str7<<endl;  
// Mc

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
Insert: Deve nation loping
Erase: Developing
Replace: Deveaddedion loping
Donalds
Mc

*/