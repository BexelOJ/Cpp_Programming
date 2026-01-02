#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;  // carry over
        }

        // If all digits were 9, we need one more digit at front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    Solution p;
    std::vector<int> digits = {9, 9, 9}; // Example input
    std::vector<int> res = p.plusOne(digits);
    
    for (auto s : res) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}

