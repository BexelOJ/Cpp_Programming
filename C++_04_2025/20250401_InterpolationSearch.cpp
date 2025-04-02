#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int key) {
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[pos] == key) {
            return pos;
        }
        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 12, 20, 32, 43, 47, 55, 69};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 32;

    int result = interpolationSearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}

