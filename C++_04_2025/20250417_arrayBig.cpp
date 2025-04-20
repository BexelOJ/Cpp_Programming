#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> solve(vector<int> &A, int B ) {
       // Min-heap to keep track of B largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : A) {
        if (minHeap.size() < B) {
            minHeap.push(num);
        } else if (num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    // Extract elements from heap into result vector
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main() {
    // cout<<"Enter the Elements: "<<endl;
    // vector<int> A[100];
    // for(int i=0; i< 20; i++)
    // {
    //     cin>>A[i];
    // }

    vector<int> A = {4, 1, 9, 3, 7, 8, 2};

    int B = 3;

    vector<int> largest = solve(A, B);

    cout << "The " << B << " largest elements are: ";
    for (int num : largest) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
