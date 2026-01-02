#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n=0;
    cin>>n;  
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    int d1=0, lr=0, ur=0;
    cin>>d1;
    cin>>lr>>ur;
    v.erase(((v.begin()+d1)-1));
    v.erase(((v.begin()+lr)-1), ((v.begin()+ur)-1));
    cout<<v.size()<<endl;
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
