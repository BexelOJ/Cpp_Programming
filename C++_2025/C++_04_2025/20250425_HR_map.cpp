#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q=0, typ=0, val=0;
    string s;
    cin>>q;
    map<string, int> mp;
    map<string, int>::iterator it;
    
    for(int i=0; i<q; i++)
    {
        cin>>typ;
        switch(typ){
            case(1):
            cin>>s>>val;
            mp[s] += val;
            mp.insert({s,val});
            break;
            
            case(2):
            cin>>s;
            it = mp.find(s);
            if(it != mp.end())
            {
             mp.erase(s);   
            }
            break;
            
            case(3):
            cin>>s;
            it = mp.find(s);
            if(it != mp.end())
            {
             cout<<it->second<<endl;  
            }
            break;
        }
    }
    
    return 0;
}


/*

7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

*/