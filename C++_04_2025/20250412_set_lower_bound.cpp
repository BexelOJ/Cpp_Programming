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

// for loop using iterator
for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    cout << *it << " ";
cout<<endl;

// for loop Using auto keyword (C++11 and later)
for (auto it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " ";
cout<<endl;


//  Using for_each and Lambda (C++11 and later)
for_each(s.begin(), s.end(), [](int x) { std::cout << x << " "; });
cout<<endl;

return 0;

}



