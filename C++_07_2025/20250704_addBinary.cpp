#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int carry = 0;

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;
            int bitB = (j >= 0) ? b[j--] - '0' : 0;

            int sum = bitA + bitB + carry;
            result += (sum % 2) + '0';  // current bit
            carry = sum / 2;            // next carry
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution p;
    std::cout << p.addBinary("11", "1") << std::endl;  // Output: "100"
    //std::cout << p.addBinary("1010", "1011") << std::endl;  // Output: "10101"
    return 0;
}
