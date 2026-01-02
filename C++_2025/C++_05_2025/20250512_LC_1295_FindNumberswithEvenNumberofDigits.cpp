#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            // Convert number to string and check its length
            if (to_string(num).length() % 2 == 0) {
                count++;
            }
        }
        return count;

        /*
        int count = 0;
        for (int num : nums) {
        int digits = 0;
        while (num) {
            num /= 10;
            digits++;
        }
        if (digits % 2 == 0) count++;
    }
    return count;
        */
    }
};

int main()
{
Solution* s = new Solution();
    vector<int> nums = {12,345,2,6,7896};
    cout << s->findNumbers(nums) << endl; // Expected: 2
    nums = {555,901,482,1771};
    cout << s->findNumbers(nums) << endl; // Expected: 1
    nums = {1000,10000,100000};
    cout << s->findNumbers(nums) << endl; // Expected: 0
    return 0;
}

