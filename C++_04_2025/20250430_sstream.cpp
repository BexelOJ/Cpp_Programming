#include <sstream>  //stringstream
#include <iostream>

int main() {
    std::string data = "42 3.14 hello";
    std::string cpp = "C Plus Plus";
    std::istringstream iss(data);
    std::istringstream iss2(cpp);

    int a;
    double b;
    std::string c;
    std::string d;
    std::string e;
    std::string f;
    iss >> a >> b >> c;
    iss2 >> d >> e >> f;
    std::cout << a << " | " << b << " | " << c << std::endl;
    std::cout << d << " " << e << " "<< f << std::endl;
    return 0;
}