#include <iostream>

void fibo(int x){
    int a=0, b=1, c=0;
    std::cout<<"Fibonacci Series: ";
    std::cout<<a<<" "<<b<<" ";
    
    while(x>2){
        c = a+b;
        std::cout<<c<<" ";
        a = b;
        b = c;
        x--;
    }
    std::cout<<std::endl;
}

int main()
{
    int n=0;
    std::cout<<"Enter a Number : "<<std::endl;
    std::cin>>n;
    fibo(n);
    return 0;
}

