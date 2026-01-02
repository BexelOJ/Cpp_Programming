#include <iostream>

void display(int* arr, int m) {
    for (int i = 0; i < m; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<< std::endl;
}

int main() {
    int a = 10;
    int& ref = a;
    
    int arr[] = { 1,2,3,4,5 };

    int* ptr = arr;
    int*& refptr = ptr;

    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    display(ptr,n);

    std::cout << " sum = " << sum << std::endl;
    std::cout << " *ptr = " << *ptr << std::endl;
    *ptr = *ptr + 10;
//    std::cout << " *ptr = " << *ptr + 10<< std::endl;
    std::cout << " *ptr = " << *ptr << std::endl;
    std::cout << " *refptr = " << *refptr << std::endl;

    std::cout << " a = " << a << std::endl;
    std::cout << " ref = " << ref << std::endl;
    a = ref + 10;

    std::cout << " a = " << a << std::endl;
    std::cout << " ref = " << ref << std::endl;

    return 0;
}



