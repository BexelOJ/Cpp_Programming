#include <iostream>
using namespace std;

int main() {
    int x = 42;

    void* vp = &x;   // 1️⃣ void* can hold the address of any type

    int* ip = (int*)vp;  // 2️⃣ C-style cast from void* to int*
    cout << *ip << endl; // 3️⃣ Dereference it → prints 42

    int* ipc = static_cast<int*>(vp);  // 4️⃣ C++ style cast
    cout << *ipc << endl;              // 5️⃣ Prints 42 again

    return 0;
}

/*
Output:

42
42

Explanation:
This code demonstrates the use of `void*` in C++. A `void*` pointer can hold the address of any data type, but it cannot be dereferenced directly. To use it, you must cast it to the appropriate type, such as `int*` in this case. The code shows both C-style and C++-style casting.
The output confirms that both casting methods work correctly, allowing access to the integer value stored at the address held by the `void*` pointer.

*/

