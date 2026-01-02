#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
            result <<= 1;           // Make space for the next bit
            result |= (n & 1);      // Copy the least significant bit of n to result
            n >>= 1;                // Shift n to the right to process the next bit
        }
        return result;
    }

};

int main()
{
uint32_t num =0;
cout<<"Enter a 32-bit Number in Binary"<<endl;
cin>>num;
Solution sol;
cout<<sol.reverseBits(num)<<endl;

return 0;
}


