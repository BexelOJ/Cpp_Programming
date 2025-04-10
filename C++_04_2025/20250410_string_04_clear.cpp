#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello, World!";
    bool is;

    cout << "Before clear(): " << s << " (size: " << s.size() << ")\n";
    cout<<"Capacity: "<<s.capacity()<<endl;

    is = s.empty();
    cout<<"String is Empty : "<<is<<endl;

    s.clear();
    
    cout << "After clear(): '" << s << "' (size: " << s.size() << ")\n";
    cout<<"Capacity: "<<s.capacity()<<endl;

    is = s.empty();
    cout<<"String is Empty : "<<is<<endl;

    s.shrink_to_fit();
    cout<<"Size: "<<s.size()<<endl;
    cout<<"Capacity: "<<s.capacity()<<endl;
    return 0;
}

/*
Output:

Before clear(): Hello, World! (size: 13)
Capacity: 15
String is Empty : 0
After clear(): '' (size: 0)
Capacity: 15
String is Empty : 1
Size: 0
Capacity: 15

*/









