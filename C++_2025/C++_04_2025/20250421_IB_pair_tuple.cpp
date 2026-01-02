#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;


pair<int, int> findMaxMin(vector<int> &A){
    // First value of pair will be Maximum of array A and second will be Minimum of array A
    int maxVal = A[0];
    int minVal = A[0];
    for (int val : A) {
        if (val > maxVal) maxVal = val;
        if (val < minVal) minVal = val;
    }
    return {maxVal, minVal}; 
}

tuple<int, int, int> compute(vector<int> &A){
    // First value of tuple will be sum of array A
    // Second value of tuple will be sum of even values in array A 
    // Third value of tuple will be sum of odd values in array A
    int total = 0, evenSum = 0, oddSum = 0;
    for (int val : A) {
        total += val;
        if (val % 2 == 0) {
            evenSum += val;
        } else {
            oddSum += val;
        }
    }
    return make_tuple(total, evenSum, oddSum);
}


int main()  {
    int n;
    cin>>n;

    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    
    pair<int, int> max_min = findMaxMin(A);
    cout<<max_min.first<<" "<<max_min.second<<endl;
    
    tuple<int, int, int> tuple_values = compute(A);
    cout<< get<0>(tuple_values) << " " << get<1>(tuple_values) << " " << get<2>(tuple_values) << endl;
    
    return 0;
}

