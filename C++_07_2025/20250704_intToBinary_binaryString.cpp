#include <iostream>
#include <string>

std::string toBinary(int num) {
    std::string result;
    for (int i = 31; i >= 0; --i) {
        result += ((num >> i) & 1) ? '1' : '0';
    }
    return result;
}

int main() {
    int num = 23; // 10111
    std::cout << "Binary string: " << toBinary(num) << std::endl;
    return 0;
}

