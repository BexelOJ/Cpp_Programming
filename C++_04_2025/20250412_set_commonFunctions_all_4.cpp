#include <iostream>
#include <set>

using namespace std;

int main()
{
    std::set<int> s = {5, 2, 3, 4, 8, 1};
    int n=0, value=0;
    // Range-Based For Loop (C++11 and later)
    for (int x : s) {
        std::cout << x << " ";
    }
    cout<<endl;
    // Output: 1 2 5 8 (sorted automatically)
    //s.clear();
    if(s.empty())
        cout<<"Set Container is Empty"<<endl;
    else
        cout<<"Set Container is Not Empty"<<endl;
    cout<<s.size()<<endl;
    // for(int i=0; i<s.size(); i++ ){
    //     cin>>value;
    //     s.insert(value);
    //     //cout<<*it<<" ";
    // }
    cout<<endl;
    for(int x : s)
        cout<<x<<" ";
    cout<<endl;

    auto itt = s.upper_bound(5);
    cout<<"Upper Bound: "<<*itt<<endl;

    auto it = s.lower_bound(5);
    cout<<"Lower Bound: "<<*it<<endl;
    return 0;
}





