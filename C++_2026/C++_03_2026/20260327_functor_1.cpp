#include <iostream>

class Adder{
    int value;
public:
    Adder(int val):value(val) {
        // std::cout<<"Adder Constructor called"<<std::endl;
    }
    int operator()(int num){
        return value + num;
    }
};

  
int main() {
    Adder a1(5);
    
    Adder* a2 = new Adder(5);


    int res = a1(15);
    std::cout << res << std::endl;
    
    int res_2 = (*a2)(2);
    std::cout << res_2 << std::endl;

    delete a2;

    return 0;
}


