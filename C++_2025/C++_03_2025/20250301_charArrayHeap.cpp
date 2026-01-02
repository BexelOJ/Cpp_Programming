#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string str1 = "Hello World"; // Initialize a string with "Hello World" in stack
    string *str2 = new string; // Allocate memory for one string
    string *str3 = new string[10];  // Allocate memory for 10 strings
    
    // Assign a value to the first string in the array
    *str2 = "Hello from array str2";
    
    str3[0] = "Hello";
    str3[1] = "Hello New";
    str3[2] = "Hello New India";
    str3[3] = "Hello New India is";
    str3[4] = "Hello New India is Developing";
    
    //str3[5] = nullptr;
    // Print the values
    cout << "str1: " << str1 << endl;
    cout << "str2: " << *str2 << endl;
    cout << "str3.0: " << str3[0] << endl;
    cout << "str3.1: " << str3[1] << endl;
    cout << "str3.2: " << str3[2] << endl;
    cout << "str3.3: " << str3[3] << endl;
    cout << "str3.4: " << str3[4] << endl;

    //cout<<"Enter a sentence: ";
    //cin.getline(str3[5],10);
    //cout << "str3.5: " << str3[5] << endl;

    // Deallocate the memory to prevent memory leak
    delete[] str2;
    delete[] str3;
    return 0;
}
