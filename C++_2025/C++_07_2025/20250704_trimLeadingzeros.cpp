#include <iostream>
#include <bitset>
#include <string>

std::string trimLeadingZeros(int num) {
    std::bitset<32> bits(num);        // 32-bit binary
    std::string binStr = bits.to_string(); // Convert to string
    size_t firstOne = binStr.find('1');

    // If num is 0, we still want to return "0"
    std::string res = (firstOne == std::string::npos) ? "0" : binStr.substr(firstOne);
    return res;
}

int main() {
    int num = 23;
    std::string trimmedBinary = trimLeadingZeros(num);
    std::cout << "Binary without leading zeros: " << trimmedBinary << std::endl;
    return 0;
}

