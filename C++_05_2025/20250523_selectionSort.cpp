#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {3,4,2,5,1};
    int n = v.size();
    int minIndex = 0;
    for(int i=0; i<n-1; ++i){
        minIndex = i;
        for(int j=i+1; j<n; ++j){
            if(v[j] < v[minIndex]){
                minIndex = j;
            }

        }
        
        swap(v[i], v[minIndex]);
    
}

    cout << "Sorted array: ";
    for(auto n : v){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

