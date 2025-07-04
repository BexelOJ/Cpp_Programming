#include <iostream>
#include <string>
#include <algorithm>    
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        // Ensure both strings are non-empty
        if (a.empty() && b.empty()) return "0";
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        // Convert strings to integers
        int b1 = std::stoi(a, nullptr, 2);
        int b2 = std::stoi(b, nullptr, 2);
        std::cout<<"b1: "<<b1<<" "<<"b2: "<<b2<<std::endl;
        // Using bitwise operations to add two integers
       
       
        while (b2 != 0) {
            int carry = (b1 & b2) << 1;  // bits to carry over
            b1 = b1 ^ b2;                 // sum without carry
            b2 = carry;                 // update b to carry
        }

        std::cout<<"b1 : "<<b1<<std::endl;
        
        std::string result;
        bool started = false;
        for (int i = 31; i >= 0; --i) {
            bool bit = (b1 >> i) & 1;
            if (bit) started = true;
            if (started) result += bit ? '1' : '0';
        }
        std::string str =  result.empty() ? "0" : result;

        std::cout<<"str: "<<str<<std::endl;
        // Convert the result back to binary string
        std::string result2;
        for (int i = 31; i >= 0; --i) {result2 += ((b1 >> i) & 1) ? '1' : '0';
        }
        
        // Remove leading zeros
        size_t firstOne = result2.find('1');
        if (firstOne == std::string::npos) {
            return "0"; // If no '1' found, the result is zero
        }
        result2 = result2.substr(firstOne); // Trim leading zeros
        //std::cout << "Binary without leading zeros: " << result << std::endl
        return result2;
    }
};

int main(){
    Solution p;
    std::cout<<p.addBinary("11", "1")<<std::endl;
    return 0;
}




