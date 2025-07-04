#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

void printBinaryAndHex(int num) {
    // Convert to binary using std::bitset
    std::bitset<32> binary(num);
    std::string trimmedBinary = binary.to_string().substr(binary.to_string().find('1'));

    // Convert to hexadecimal using stringstream
    std::stringstream ss;
    ss << std::hex << std::uppercase << num;
    std::string hexStr = ss.str();

    std::cout << "Decimal     : " << num << std::endl;
    std::cout << "Binary      : " << (num == 0 ? "0" : trimmedBinary) << std::endl;
    std::cout << "Hexadecimal : 0x" << hexStr << std::endl;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    printBinaryAndHex(num);
    return 0;
}

