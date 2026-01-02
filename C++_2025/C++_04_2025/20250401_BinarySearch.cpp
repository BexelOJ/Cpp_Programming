#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;
        
        // If key is smaller, ignore the right half
        if (arr[mid] > key)
            high = mid - 1;
        
        // If key is greater, ignore the left half
        else
            low = mid + 1;
    }
    
    // Key not found
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, 0, n-1, key);
    if (result != -1)
        cout << "Element is present at index " << result << endl;
    else
        cout << "Element is not present in array" << endl;

    return 0;
}

