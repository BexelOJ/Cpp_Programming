#include <iostream>
#include <array>

using namespace std;

int main()
{
    // Initialize a std::array with 5 elements
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

    // Using begin() and end() for iteration
    std::cout << "Using begin() and end() to iterate through array:\n";

    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n\n";
    // Using cbegin() and cend() for constant iteration (read-only)

    std::cout << "Using cbegin() and cend() for constant iteration:\n";
    for (auto it = arr.cbegin(); it != arr.cend(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n\n";
    // Using data() to access the underlying array (pointer to the first element)

    std::cout << "Using data() to access underlying array:\n";

    int* data_ptr = arr.data();

    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << data_ptr[i] << " ";
    }

    std::cout << "\n\n";
    // Using empty() to check if the array is empty

    std::cout << "Using empty() to check if array is empty:\n";

    if (arr.empty())
    {
        std::cout << "Array is empty.\n";
    }

    else
    {
        std::cout << "Array is not empty.\n";
    }

    std::cout << "\n";
    // Using rbegin() and rend() for reverse iteration

    std::cout << "Using rbegin() and rend() for reverse iteration:\n";

    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
    {
        std::cout << *it << " ";
    }


    std::cout << "\n\n";

    cout << *(arr.rbegin()) << endl;
    cout << *(arr.rend() - 1) << endl;
    cout << *(arr.cbegin()) << endl;
    cout << *(arr.cend() - 1) << endl;
    return 0;
}



