#include <iostream>
using namespace std;

void decToBinBitwise(int n) 
{
    for (int i = 31; i >= 0; i--) {
        // Shift the bit at position i to the rightmost bit
        int bit = (n >> i) & 1;
        cout << bit;
    }
    cout << endl;
}

int main() 
{
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    
    cout << "Binary representation (using bitwise): "<<endl;
    decToBinBitwise(num);
    
    return 0;
}

/*

00000000000000000000000000010111
0000 0000 0000 0000 0000 0000 0001 0111

*/
