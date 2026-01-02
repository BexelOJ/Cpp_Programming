#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index of the found element
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {12, 34, 55, 23, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
    
    int index = linearSearch(arr, n, key);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}

