#include <iostream>

int add(int x, int y) {
    int sum = x + y;
    return sum;
}

int main() {
    int a = 0, b = 0;
    std::cout << "Enter two Integers: " << std::endl;
    std::cin >> a >> b;
    int *fnptr(int, int) = add;
 //   fnptr = add;
    int res = fnptr(a, b);
    std::cout << res << std::endl;
    return 0;
}


