#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.size();
        int l2 = b.size();
        string res = 0;
        for(int i=0; i<l1; i++){
           res[i] = a[i] + b[i]; 
            if()
        }
        return res;
    }
};


int main()
{
string s1, s2;

cout<<"Enter First Binary"<<endl;
cin>>s1;
cout<<"Enter Second Binary"<<endl;
cin>>s2;

Solution sol;
cout<<sol.addBinary(s1, s2)<<endl;
return 0;
}


