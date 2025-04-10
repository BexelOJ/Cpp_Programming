#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()  {
    int N=0, X=0;
    cin>>N;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
       cin>>v[i];
    }
    cout<<"Size = "<<v.size()<<endl;
    cout<<endl;
    cin>>X;
    v.erase(v.begin()+X);
    sort(v.begin(), v.end());
    
    for(int i=0; i<(N-1); i++){
        cout<<v[i]<<" ";
    }    
    v.push_back(11);
    v.push_back(12); 
    cout<<endl;
    cout<<"Size = "<<v.size()<<endl;
    cout<<endl;
        for(int i=0; i<(v.size()); i++){
        cout<<v[i]<<" ";
    }  
    cout<<endl;
    return 0;
}


/*
Output:

5
2 3 5 4 1
Size = 5

3
1 2 3 5 
Size = 6

1 2 3 5 11 12 

*/

