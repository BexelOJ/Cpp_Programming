#include <iostream>
#include <memory>

int addition(  int a, int b){
    std::cout<<"Inside Addition Function"<<std::endl;
    return a+b;
}

int subtraction(int a, int b){
    std::cout<<"Inside Subtraction Function"<<std::endl;
    return a-b;
} 

int multiplication(int a, int b){
    std::cout<<"Inside Multiplication Function"<<std::endl;
    return a*b;
}

int division(int a, int b){
    if(a < b){
        std::cout<<"Error: Dividend should be greater than Divisor"<<std::endl;
        return 0;
    }
    std::cout<<"Inside Division Function"<<std::endl;    
    return a/b;
}

int main(){
    int a = 0, b = 0;
    std::cout<<"Enter the Dividend: "<<std::endl;
    std::cin>>a;
    std::cout<<"Enter the Divisor: "<<std::endl;
    std::cin>>b;

    std::cout<<"Addition of "<<a<<" and "<<b<<" is : "<<addition(a,b)<<std::endl;
    
    std::cout<<"Subtraction of "<<b<<" from "<<a<<" is : "<<subtraction(a,b)<<std::endl;
    
    std::cout<<"Multiplication of "<<a<<" and "<<b<<" is : "<<multiplication(a,b)<<std::endl;
    
    std::cout<<"Division of "<<a<<" and "<<b<<" is : "<<division(a,b)<<std::endl;

    return 0;
}


