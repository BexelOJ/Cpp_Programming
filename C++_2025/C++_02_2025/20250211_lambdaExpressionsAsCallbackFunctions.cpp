#include <iostream>

void processData(int data, std::function<void(int)> callback) {
    std::cout << "Processing data: " << data << std::endl;
    callback(data);
}

int main() {
    int data = 42;

    // Use a lambda function as the callback
    processData(data, [](int value) {
        std::cout << "Lambda callback called with value: " << value << std::endl;
    });

    return 0;
}

