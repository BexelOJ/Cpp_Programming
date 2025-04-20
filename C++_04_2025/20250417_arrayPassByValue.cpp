#include <iostream>
#include <array>

using namespace std;

int modify(array<int, 3> arr) {
    arr[0] = 999; // Changes only the local copy
    cout << arr[0] << endl;
    return arr[0];
}

int main() {
    array<int, 3> arr = {1, 2, 3};
    modify(arr);
    cout << arr[0] << endl; // Output: 1 (original array unchanged!)
    return 0;
}



// template<typename T, size_t N>
// struct array {
//     T data[N]; // actual storage
//     size_t size() const { return N; }
//     // operator[], begin(), end(), etc.
// };
