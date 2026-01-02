#include <iostream>
using namespace std;

// Template function for finding the maximum of two values
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 10 and 20 is: " << myMax(10, 20) << endl;
    cout << "Max of 3.5 and 2.5 is: " << myMax(3.5, 2.5) << endl;
    cout << "Max of 'a' and 'z' is: " << myMax('a', 'z') << endl;
    return 0;
}



