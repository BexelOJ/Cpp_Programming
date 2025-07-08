#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

class Solution {
public:
     int power(int x){
            int s = 0, res = 1;
            for(int i=0 ; i<x; i++){
                 res *= 10;
            }
            return res;
        }
    std::vector<int> addToArrayForm(std::vector<int>& digits, int k) {
        int s = digits.size(), sum=0, num=0;;
        reverse(digits.begin(),digits.end());

        for(int i=(s-1); i>=0; i--){
            sum = ((power(i) * digits[i] )+ sum );
        }
        sum = sum + k;  // Adding k to the sum
        num = sum;
        
        std::vector<int> result;
        
        while(num){
            s = num%10;
            result.push_back(s);
            num = num/10;
        }
        reverse(result.begin(),result.end());
        return result;  
    }
};

int main() {
    Solution p;
    std::vector<int> digits = {9,9,9};
    int k = 34;
    std::vector<int> res = p.addToArrayForm(digits,k);
    for(auto s: res){
            std::cout<<s<<" ";
        }
    std::cout<<std::endl;
    return 0;
}


