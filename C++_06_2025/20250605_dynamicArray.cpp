#include <iostream>
using namespace std;

// Renamed function
void print2DArray(int x, int y, int** arr) {
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << *arr[0] << endl;
    cout << *arr[1] << endl;
    cout << *arr[2] << endl;
    cout << *arr[3] << endl;
    cout << *arr[4] << endl;

    cout << *(arr[0]+1) << endl;
    cout << *(arr[1]+1) << endl;
    cout << *(arr[2]+1) << endl;
    cout << *(arr[3]+1) << endl;
    cout << *(arr[4]+1) << endl;
}

int main() {
    int a = 0, b = 0;

    cout << "Enter the Number of Rows and Columns: ";
    cin >> a >> b;

    // Dynamic memory allocation
    int** arr = new int*[a]; // Array of pointers to int
    for (int i = 0; i < a; i++) {
        arr[i] = new int[b];
    }

    cout << "Enter the Elements for " << a << " rows and " << b << " columns:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }

    print2DArray(a, b, arr);

    // Free the memory
    for (int i = 0; i < a; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

