#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        vector<int> res;
        for(int i=0; i<(s-1); i++)
        {
            for(int j=i+1; j<s; j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    res.push_back(i);
                    res.push_back(j);  
                    //return res;                 
                }
            }  
        }
        return res;
    }
};

int main()
{
vector<int> nums = {2, 7, 11, 15};
int target = 9;
Solution s;
vector<int> result = s.twoSum(nums, target);
for(int i=0; i<result.size(); i++)
{
    cout << result[i] << " ";
}
cout << endl;

return 0;
}


