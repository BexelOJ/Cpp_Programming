#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int a = 0; // Red
        int b = 0; // White
        int c = 0; // Blue
        // enum color{0, 1, 2};
        // i need an enum for color
        enum color { RED = 0, GREEN = 1, BLUE = 2 };

        for(int i=0; i<s; i++){
            switch(nums[i]){
                case 0:
                    a++;
                    //nums[i] = 0;
                    break;
                case 1:
                    b++;
                    //nums[i] = 1;
                    break;
                case 2:
                    c++;
                    //nums[i] = 2;
                    break;
            }
        }
        cout<<"Red: "<<a<<endl;
        cout<<"White: "<<b<<endl;
        cout<<"Blue: "<<c<<endl; 
        
        for(int i=0; i<s; i++){
            if(i<a){
                nums[i] = 0;
            }else if(i<a+b){
                nums[i] = 1;
            }else{
                nums[i] = 2;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    
    s.sortColors(nums);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}


