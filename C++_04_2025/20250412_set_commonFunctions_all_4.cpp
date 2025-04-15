#include <iostream>
#include <set>

using namespace std;

int main()
{
    std::set<int> s = {5, 2, 8, 1};

    // Range-Based For Loop (C++11 and later)
    for (int x : s) {
        std::cout << x << " ";
    }
    cout<<endl;
    // Output: 1 2 5 8 (sorted automatically)


    // Using Iterator Explicitly
    for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
    }
    //Or with C++11 auto:
    for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
    }


    return 0;
}





