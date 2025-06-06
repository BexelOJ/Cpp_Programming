#include <iostream>
using namespace std;

void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        
        merge(arr, left, mid); // Sort the left half
        merge(arr, mid + 1, right); // Sort the right half
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int L[n1], R[n2];
        
        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    merge(arr, 0, n-1);
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

