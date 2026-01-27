#include <iostream>

// Define a callback function type (function pointer)
typedef void (*CallbackFunction)(int);

// A function that takes a callback function as an argument
void processData(int data, CallbackFunction callBack){
    std::cout << "Processing data: " << data << std::endl;
 
    // Call the callback function
    callBack(data);
}

// Define a function that will be used as a callback
void myCallback(int value) {
    std::cout << "Callback function called with value: " << value << std::endl;
}

int main() {
    int data = 42;
    
    // Call processData and pass the callback function
    processData(data, myCallback);

    return 0;
}

/*
OUTPUT:
Processing data: 42
Callback function called with value: 42

*/

