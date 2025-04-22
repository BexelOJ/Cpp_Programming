#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
set<int> s1 = {2,4,6,8,3,5,1,7,9};
unordered_set<int> s2 = {2,4,6,8,3,5,1,7,9};

for(int x: s1){
    cout<<x<<" ";
}
cout<<endl;
// 1 2 3 4 5 6 7 8 9

for(int x: s2){
    cout<<x<<" ";
}
cout<<endl;
// 9 7 1 5 3 8 6 4 2

return 0;
}


/*
OUTPUT:
1 2 3 4 5 6 7 8 9 
9 7 1 5 3 8 6 4 2 

*/

