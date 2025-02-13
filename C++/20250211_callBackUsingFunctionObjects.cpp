#include <iostream>

class MyCallback 
{
public:
    void operator()(int value) 
    {
        std::cout<<"Function object called with value: "<<value<<std::endl;
    }
};

void processData(int data, MyCallback callback) 
{
    std::cout << "Processing data: " << data << std::endl;
    callback(data);
}

int main() 
{
    int data = 42;
    
    // Use function object as a callback
    MyCallback callback;
    processData(data, callback);

    return 0;
}



