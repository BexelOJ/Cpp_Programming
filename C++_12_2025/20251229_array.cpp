#include <iostream>


int add(int* arr, int n) {
    
    int* ptr = arr;
    std::cout << "arr address: " << arr << std::endl;
    std::cout << "ptr address: " << ptr << std::endl;
    std::cout << "ptr value: " << *ptr << std::endl;
    std::cout << "ptr + 1 value: " << *(ptr+1) << std::endl;

    int sum = 0;

    std::cout << "n = " << n << std::endl;
    
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

int addTwo(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int arr[] = { 5,9,5,8,2,4,6,12 };
    int* ptr = arr;
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    std::cout << "Sum 1 = " << sum << std::endl;

    int res = add(ptr,n);
    std::cout << "Sum 2 = " << res << std::endl;

    int(*fnptr)(int*, int);
    fnptr = add;
    int addRes = 0;
    addRes = fnptr(ptr, n);
    std::cout << "addTwo res = " << addRes << std::endl;

    return 0;
}



