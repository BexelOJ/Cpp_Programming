#include <iostream>

void func(){
    std::cout << "Inside func()\n";
}

int main(){
    std::cout << "Program Started\n";
    int a = 10;
    int b = 20;
    int c = a + b;

    func();

    std::cout << "Sum = " << c << '\n';
    
    return 0;

}


