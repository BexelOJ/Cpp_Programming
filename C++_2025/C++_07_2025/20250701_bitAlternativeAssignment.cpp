#include <iostream>
#include <ciso646>

using namespace std;

int main() {
    int x = 6;   // 0110
    int y = 3;   // 0011

    x and_eq y;  // x = x & y → 0110 & 0011 = 0010 (2)
    cout << "x after and_eq y: " << x << endl;

    x = 6;       // reset to original
    x or_eq y;   // x = x | y → 0110 | 0011 = 0111 (7)
    cout << "x after or_eq y: " << x << endl;

    x = 6;
    x xor_eq y;  // x = x ^ y → 0110 ^ 0011 = 0101 (5)
    cout << "x after xor_eq y: " << x << endl;

    cout << "x not_eq y: " << (x not_eq y) << endl; // true (1)
    
    return 0;
}

