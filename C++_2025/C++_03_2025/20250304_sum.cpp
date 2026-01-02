#include <iostream>
using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return (num1 + num2);
    }
    //Solution(int x, int y):num1(x), num2(y){}
};

int main()
{
Solution s1;
int a=0, b=0;
cin>>a>>b;
cout<<s1.sum(a,b)<<endl;
return 0;
}


