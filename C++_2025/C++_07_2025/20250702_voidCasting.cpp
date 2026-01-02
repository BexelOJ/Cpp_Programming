#include <iostream>
using namespace std;

int main() {
    int x = 42;

    // Step 1: Declare a void pointer and assign it the address of x
    void* vp = &x;

    // cout<<*vp<<endl; // error: ‘void*’ is not a pointer-to-object type
    
    // Step 2: Cast the void pointer back to an int pointer
    int* ip = static_cast<int*>(vp);

    // Step 3: Access the value using the casted pointer
    cout << "Value from void pointer (after casting): " << *ip << endl;

    return 0;
}

/*
Output:
Value from void pointer (after casting): 42
Explanation:
This code demonstrates how to use a `void*` pointer in C++. A `void*` pointer can hold the address of any data type, but it cannot be dereferenced directly. To use it, you must cast it to the appropriate type, such as `int*` in this case. The code shows how to declare a `void*` pointer, assign it the address of an integer variable, and then cast it back to an `int*` pointer to access the value stored at that address. The output confirms that the value is correctly retrieved after casting.

*/

/*
Note: The code uses `static_cast` for type casting, which is the preferred way in C++ for type safety.
C-style casting can also be used, but `static_cast` is safer and more explicit. It ensures that the cast is valid and helps prevent errors that can occur with C-style casts,
such as accidentally casting to an incompatible type.
*/