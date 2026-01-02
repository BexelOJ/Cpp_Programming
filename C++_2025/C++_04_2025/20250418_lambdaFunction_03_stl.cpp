#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> nums = {5, 2, 9, 1};

    // Sort in descending order using a lambda
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });

    for (int n : nums) {
        cout << n << " ";
    }
    cout<<endl;
    // 9 5 2 1
    

    // Sort in ascending order using a lambda
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a < b;
    });

    for (int n : nums) {
        cout << n << " ";
    }
    cout<<endl;
    // 1 2 5 9

    return 0;
    return 0;
}

