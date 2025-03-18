#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    int index = 0;
    for (int num : arr) {
        std::cout << "Array at index " << index << " : " << num << std::endl;
        ++index;
    }
    arr.fill(10);
    for (int num : arr) {
        std::cout << "After fill with 10: " << num << std::endl;
    }
    std::cout << "Array size: " << arr.size() << std::endl;

    return 0;
}


