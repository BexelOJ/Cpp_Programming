#include <iostream>

using namespace std;

int main(){
    int a = 10;
    const int b = 20;
    static int s = 30;
    const static int cs = 40;
    
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"s: "<<s<<endl;
    cout<<"cs: "<<cs<<endl<<endl;
    
    int& r = a;
    const int& c = b;
    int& s2 = s;
    const static int& cs2 = cs;
    
    cout<<"Reference of a       : "<<r<<endl;    
    cout<<"Reference of const b : "<<c<<endl;
    cout<<"Reference of static s : "<<s2<<endl;
    cout<<"Reference of const static cs : "<<cs2<<endl<<endl;
    
    a++;
    //b++;
    s++;
    //cs++;
    
    cout<<"Reference of a       : "<<r<<endl;    
    cout<<"Reference of const b : "<<c<<endl;
    cout<<"Reference of static s : "<<s2<<endl;
    cout<<"Reference of const static cs : "<<cs2<<endl;
    
    return 0;
}



