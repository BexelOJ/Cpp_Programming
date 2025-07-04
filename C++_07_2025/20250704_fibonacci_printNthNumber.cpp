#include <iostream>

void fibo(int x){
    int a=0, b=1, c=0;
    
    if(x == 1) {
        std::cout << "1st number in Fibonacci Series: " << a << std::endl;
        return;
    } else if(x == 2) {
        std::cout << "2nd number in Fibonacci Series: " << b << std::endl;
        return;
    } else if(x == 3){
        std::cout<<x<<"rd number in Fibonacci Series: "; 
    } else {
       std::cout<<x<<"th number in Fibonacci Series: "; 
    }
    
    while(x>2){
        c = a+b;
        //cout<<c<<" ";
        a = b;
        b = c;
        x--;
    }
    std::cout<<c<<std::endl;
}

int main()
{
    int n=0;
    std::cout<<"Enter a Number : "<<std::endl;
    std::cin>>n;
    fibo(n);
    return 0;
}
