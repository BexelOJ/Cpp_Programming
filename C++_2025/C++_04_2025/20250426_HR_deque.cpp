#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;  

using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
   
    deque<int> dq(k);
    int i;
    for(i=0; i<k; i++){
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    cout<<arr[dq.front()]<<" ";
    
    for(i=k; i<n; i++){
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    

    cout<<endl;
}

}

int main(){
  
	int t;
	cin >> t;

	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];

    	for(i=0;i<n;i++)
      		cin >> arr[i];

    	printKMax(arr, n, k);
    	t--;
  	}

  	return 0;
}

/*
Input:
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

Output:
4 6 6 4
8 8 8 10

*/