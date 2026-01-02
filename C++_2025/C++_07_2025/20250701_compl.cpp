#include <iostream>
#include <ciso646>

using namespace std;

int main() {
    int x = 5;  // Binary: 0000 0101

    cout << "~x     = " << ~x     << endl; // Using ~
    int y = compl x;
    cout << "compl x = " << y << endl; // Using keyword

    for(int i=31; i>=0; --i) {
        cout << ((x >> i) & 1); // Print each bit of x
    }
    cout << endl;
    
    for(int i=31; i>=0; --i) {
        cout << ((y >> i) & 1); // Print each bit of x
    }
    cout << endl;

    return 0;
}

