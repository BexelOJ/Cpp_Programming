
#include<iostream>
using namespace std;


void reverseArray(int arr[], int N){
    // Your code goes here
    int arr2[N];
    for(int i=0;i<N;i++)
    {
        arr2[i] = arr[i];
    }
    
    for(int i=0, j=(N-1); i<(N); i++,j--)
    {
        arr[i] = arr2[j];
    }
}



int main()  {
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    reverseArray(arr, N);
    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

