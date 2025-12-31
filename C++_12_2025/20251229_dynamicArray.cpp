#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter the Size of the Array: " << std::endl;
    std::cin >> n;
    
    //int* arr = new int[n];
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i * 20;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}


