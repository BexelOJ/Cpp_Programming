#include <iostream>

class MyCallback {
    int value;
public:
    int operator()(int val) {
        //value = val;
        std::cout << "Inside Operator Overloading" << std::endl;
        return val + 20;
    }
};

int processing(int data, MyCallback cb) {
    std::cout << "Inside Function: Processing" << std::endl;
    return cb(data);
}

int main() {
    int data = 45;
    MyCallback callback;
    std::cout<<"Final Result: "<<processing(data, callback) << std::endl;
    return 0;
}



