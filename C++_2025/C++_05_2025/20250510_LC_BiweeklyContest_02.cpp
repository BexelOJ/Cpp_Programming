/*
You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.

A subarray is a contiguous sequence of elements within an array.
 

Example 1:

Input: nums = [0,2]

Output: 1

Explanation:

Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
Thus, the minimum number of operations required is 1.
Example 2:

Input: nums = [3,1,2,1]

Output: 3

Explanation:

Select subarray [1,3] (which is [1,2,1]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [3,0,2,0].
Select subarray [2,2] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [3,0,0,0].
Select subarray [0,0] (which is [3]), where the minimum non-negative integer is 3. Setting all occurrences of 3 to 0 results in [0,0,0,0].
Thus, the minimum number of operations required is 3.
Example 3:

Input: nums = [1,2,1,2,1,2]

Output: 4

Explanation:

Select subarray [0,5] (which is [1,2,1,2,1,2]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [0,2,0,2,0,2].
Select subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,2,0,2].
Select subarray [3,3] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,2].
Select subarray [5,5] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,0].
Thus, the minimum number of operations required is 4.
 

Constraints:

1 <= n == nums.length <= 105
0 <= nums[i] <= 105
*/

/*
To solve this problem efficiently, we can use a divide-and-conquer approach.

Key Insight:
Each operation allows us to:

Pick a subarray [i, j].

Identify the minimum non-zero value in that subarray.

Set all occurrences of that minimum value within the subarray to zero.

We have two options in a given segment:

Do operations individually for each non-zero element (i.e., brute force way – as many operations as there are non-zeros).

Choose a minimum in the segment, subtract it from all non-zero elements (conceptually), and recursively apply the logic to subsegments split by zeros.

We use recursion to minimize the number of operations required.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        if (l > r) return 0;

        int min_val = INT_MAX;
        for (int i = l; i <= r; ++i) {
            if (nums[i] != 0) min_val = min(min_val, nums[i]);
        }

        if (min_val == INT_MAX) return 0; // All zero in range

        for (int i = l; i <= r; ++i) {
            if (nums[i] != 0) nums[i] -= min_val;
        }

        int ops = min_val;
        int i = l;
        while (i <= r) {
            while (i <= r && nums[i] == 0) ++i;
            int start = i;
            while (i <= r && nums[i] != 0) ++i;
            ops += solve(nums, start, i - 1);
        }

        return min(ops, r - l + 1);
    }

    int minimumOperations(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {0, 2};
    cout << "Output: " << sol.minimumOperations(nums1) << endl;  // Expected: 1

    // Test case 2
    vector<int> nums2 = {3, 1, 2, 1};
    cout << "Output: " << sol.minimumOperations(nums2) << endl;  // Expected: 3

    // Test case 3
    vector<int> nums3 = {1, 2, 1, 2, 1, 2};
    cout << "Output: " << sol.minimumOperations(nums3) << endl;  // Expected: 4

    return 0;
}


/*
Time Complexity:
O(n log M) where n is the size of the array and M is the maximum value in the array.

Each recursive call processes only the segments with non-zero values, and subtracting the minimum helps reduce values progressively.
*/

