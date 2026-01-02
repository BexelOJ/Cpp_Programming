#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int s = arr.size();
        if (s < 3) return false;
        for (int i = 0; i < s - 2; i++) {
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> arr = {1,2,3,4};
    cout << s->threeConsecutiveOdds(arr) << endl; // Expected: 0
    arr = {2,2,2,1,1,1};
    cout << s->threeConsecutiveOdds(arr) << endl; // Expected: 1
    arr = {1,2,3,4,5,6};
    cout << s->threeConsecutiveOdds(arr) << endl; // Expected: 0
    arr = {1,3,5,7,9};
    cout << s->threeConsecutiveOdds(arr) << endl; // Expected: 1


    return 0;
}



