// Bubble Sort in C++
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}





/*
Explanation of Time Complexities:

Bubble Sort: O(n²) - In the worst case, for each element, we compare it with every other element.

Insertion Sort: O(n²) - For each element, we may shift all elements to make space for it.

Selection Sort: O(n²) - For each element, we find the minimum from the unsorted part.

Merge Sort: O(n log n) - Divides the array into halves and merges them recursively.

Quick Sort: O(n log n) on average but can degrade to O(n²) in the worst case (if pivot is chosen poorly).

*/