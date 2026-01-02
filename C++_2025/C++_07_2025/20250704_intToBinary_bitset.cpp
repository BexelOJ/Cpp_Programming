#include <iostream>
#include <bitset>

int main() {
    int num = 23; // 10111 in binary, 0x17 in hex;

    std::bitset<8> binary_8(num);  // 32-bit representation
    std::bitset<16> binary_16(num);
    std::bitset<32> binary_32(num);
    std::bitset<64> binary_64(num);

    std::cout<<"08: "<<binary_8<<std::endl;
    std::cout<<"16: "<<binary_16<<std::endl;

    std::cout<<"32: "<<binary_32<<std::endl;
    std::cout<<"64: "<<binary_64<<std::endl;

    //std::cout << "Binary: " << binary << std::endl;
    return 0;
}

/*
Output:

08: 00010111
16: 0000000000010111
32: 00000000000000000000000000010111
64: 0000000000000000000000000000000000000000000000000000000000010111

*/
