#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
set<int> s = {1,2,2,3,3,4,4,5};

// Range-based for loop (C++11 and later)
for(int x : s)
    cout<<x<<" ";
cout<<endl;
// 1 2 3 4 5

// using iterator
for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    cout << *it << " ";
cout<<endl;
// 1 2 3 4 5

// using auto keyword (C++11 and later)
for (auto it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " ";
cout<<endl;
// 1 2 3 4 5

//  Using for_each and Lambda (C++11 and later)
for_each(s.begin(), s.end(), [](int x) { std::cout << x << " "; });
cout<<endl;
// 1 2 3 4 5

for_each(s.begin(), s.end(), [](int x) { std::cout << x * x << " "; });
cout<<endl;
// 1 4 9 16 25

for_each(s.begin(), s.end(), [](int x) { std::cout << x + 10 << " "; });
cout<<endl;
// 11 12 13 14 15

return 0;

}


/*
OUTPUT:
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 4 9 16 25 
11 12 13 14 15 

*/