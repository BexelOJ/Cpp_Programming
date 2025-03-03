#include <iostream>
#include <cstdint>

using namespace std;

void decToBinBitwise_64(uint64_t n) 
{
    // Shift the bit at position i to the rightmost bit
    for (int i=63; i>=0; i--)  
        cout<<((n >> i) & 1);
    cout << endl;
}

void decToBinBitwise_32(uint32_t n) 
{
    // Shift the bit at position i to the rightmost bit
    for (int i=31; i>=0; i--)  
        cout<<((n >> i) & 1);
    cout << endl;
}

int main() 
{
    int num;
    uint32_t num32;
    uint64_t num64;
    cout << "Enter a decimal numbers: ";
    cin >> num;
    num32 = num;
    num64 = num;

    cout << "Binary representation (using bitwise): "<<endl;
    
    decToBinBitwise_32(num32);
    decToBinBitwise_64(num64);

    return 0;
}


/*

00000000000000000000000000010111  // 32 bit
0000000000000000000000000000000000000000000000000000000000010111  // 64 bit

*/
