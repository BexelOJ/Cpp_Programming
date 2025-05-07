#include <iostream>
#include <vector>
using namespace std;
// 26. Remove Duplicates from Sorted Array
// Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if (l == 0) return 0;
        int i = 0;
        for (int j = 1; j < l; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};


int main()
{
    vector<int> nums = {1,1,2,2,2,3,3,4,4,4,4,4,5,5,5,5,5};
    Solution s;
    int len = s.removeDuplicates(nums);
    cout << len << endl;
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;

}





