
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "\nArray before action: " << std::endl;
    for (int x : arr)
        cout << x << " ";

    reverseArray(arr, n);

    std::cout << "\n\nFinal Array: " << std::endl;
    for (int x : arr)
        cout << x << " ";
    std::cout << "\n" << std::endl;
    return 0;
}



