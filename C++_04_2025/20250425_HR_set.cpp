#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int> s;
    int q=0, typ=0, val=0, cnt=0;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>typ>>val;
    switch(typ){
        case(1):
            s.insert(val);
            break;
        case(2):
            s.erase(val);
            break;
        case(3):
                if (s.find(val) != s.end())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                break;

    }
}
    return 0;        
}



/*

8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

*/