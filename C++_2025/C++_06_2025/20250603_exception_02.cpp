#include <iostream>
using namespace std;

void riskyFunction(bool shouldThrow) {
    if (shouldThrow) {
        throw runtime_error("An error occurred");
    }
    cout << "No error, function runs fine.\n";
}

int main() {
    try {
        cout << "Inside try block.\n";
        riskyFunction(false); // change to true to see catch run
        cout << "Still in try block, no exception.\n";
    } catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    cout << "Program continues...\n";
    return 0;
}

