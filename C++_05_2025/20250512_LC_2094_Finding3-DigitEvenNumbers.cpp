#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        int n = digits.size();
        if (n < 3) return result;

        // Sort the digits to generate numbers in ascending order
        sort(digits.begin(), digits.end());
        for (int num : result) {
            cout << num << " ";
            }
        cout << endl; 

        // Generate all 3-digit combinations
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue; // Skip leading zero
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 == 0) { // Check if the last digit is even
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        result.push_back(num);
                    }
                }
            }
        }

        // Remove duplicates and sort the result
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> digits = {2, 1, 3, 0};
    vector<int> result = s->findEvenNumbers(digits);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Expected: 120 130 210 230 320
    return 0;
}

