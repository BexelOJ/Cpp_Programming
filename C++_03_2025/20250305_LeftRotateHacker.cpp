#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
    // Ensure d is within the bounds of the array size
    d = d % arr_count;

    // Allocate memory for the result array
    int* result = (int*)malloc(arr_count * sizeof(int));
    *result_count = arr_count; // Set the result count

    // Perform the rotation
    for (int i = 0; i < arr_count; i++) {
        result[i] = arr[(i + d) % arr_count];
    }

    return result;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = 6, d = 0;;
    cout << "Enter the NUmber of Rotations: " << endl;
    cin >> d;
    int result_count;

    // Call rotateLeft function
    int* result = rotateLeft(d, n, arr, &result_count);

    // Print the result
    for (int i = 0; i < result_count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Don't forget to free the allocated memory
    return 0;
}

