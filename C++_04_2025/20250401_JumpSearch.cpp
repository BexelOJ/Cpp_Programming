#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n); // Determine the block size
    int prev = 0;
    
    // Jump ahead in steps
    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    
    // Perform linear search within the block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == key)
            return i;
    }
    
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 15;

    int result = jumpSearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}

