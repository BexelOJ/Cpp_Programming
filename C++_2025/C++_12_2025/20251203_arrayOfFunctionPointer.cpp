#include <iostream>
#include <algorithm>

using namespace std;

int add(int l, int m) {
    return l + m;
}

int sub(int l, int m) {
    return l - m;
}

int mult(int l, int m) {
    return l * m;
}

int division(int l, int m) {
    return l / m;
}

int modu(int l, int m) {
    return l % m;
}

int main() {
    int x = 0, y = 0, resAdd = 0, resSub = 0, resMult = 0, resDivision = 0, resMod = 0;

    std::cout << "Enter Two Numbers : " << std::endl;
    std::cin >> x >> y;
 
    int(*funPtr[5])(int, int) = {add, sub, mult, division, modu};

    resAdd = funPtr[0](x,y);
    resSub = funPtr[1](x, y);
    resMult = funPtr[2](x, y);
    resDivision = funPtr[3](x, y);
    resMod = funPtr[4](x, y);
    
    std::cout << x << " + " << y << " = " << resAdd << std::endl;
    std::cout << x << " - " << y << " = " << resSub << std::endl;
    std::cout << x << " * " << y << " = " << resMult << std::endl;
    std::cout << x << " / " << y << " = " << resDivision << std::endl;
    std::cout << x << " % " << y << " = " << resMod << std::endl;

    return 0;
}

/*

enum Operation { ADD, SUB, MULT, DIV, MOD };
int(*operations[5])(int, int) = {add, sub, mult, division, modu};

string opNames[] = {"Add", "Sub", "Mul", "Div", "Mod"};

for(int i = 0; i < 5; i++) {
    cout << opNames[i] << " Result: " << operations[i](x, y) << endl;
}  // Reduces code duplication [web:1][web:3]

*/


