#include <iostream>

using namespace std;

int main()
{
string str = "Manu Kumar of Bharat";
cout<<str<<endl;

for(int i=0; i<str.size(); i++){
    cout<<str[i];
}
cout<<endl;

string str2;
str2.resize(str.size());

for(int i=0; i<str.size(); i++){
    str2[i] = str[i];
    if(str[i] == 0x20){  // hex of space
        cout<<str2<<endl;
        str2.clear();
    }
//str2.clear();
}

return 0;
}

/*
Output:

Manu Kumar of Bharat
Manu Kumar of Bharat
Manu 

*/
