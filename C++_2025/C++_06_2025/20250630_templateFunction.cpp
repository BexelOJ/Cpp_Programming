#include <iostream>
using namespace std;

// Template function for addition
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "add<int>: " << add<int>(5, 10) << endl;           // Integer addition
    cout << "add<double>: " << add<double>(2.5, 3.7) << endl;   // Double addition
    cout << "add<string>: " << add<string>("Hello, ", "World!") << endl; // String addition
    return 0;
}

