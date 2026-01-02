#include <iostream>
#include <algorithm>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 0, y = 0, res =0;

    std::cout << "Enter two numbers : " << std::endl;
    std::cin >> x >> y;

    int(*funPtr)(int, int);
    funPtr = &add;
    res = funPtr(x, y);

    /* // Array of Function Pointer:
    
    int(*funPtr[5])(int, int) = {add, sub, mult, division, modu};

    resAdd = funPtr[0](x,y);
    resSub = funPtr[1](x, y);
    resMult = funPtr[2](x, y);
    resDivision = funPtr[3](x, y);
    resMod = funPtr[4](x, y);
    
    */

    /*
    
    */

    std::cout << "Add Result : " << res << std::endl;

    return 0;
}

