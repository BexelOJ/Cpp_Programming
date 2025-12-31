#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int arr[] = {1, 5, 8, 2, 9, 3, 7, 4};
    int l = sizeof(arr)/4;

    std::cout << "Before Sorting: " << std::endl;
    for (int i = 0; i < l; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << "After Sorting: " << std::endl;
    for (int i = 0; i < l; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

