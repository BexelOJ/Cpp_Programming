#include <iostream>
#include <string>

struct Flags
{
    unsigned int a : 1;
    unsigned int b : 1;
};

int main()
{
    std::cout << "Hello World" << std::endl;

    std::string s = "India";
    std::cout << s << std::endl;

    Flags f;

    f.a = 0;
    f.b = 1;

    std::cout << f.a << std::endl;
    std::cout << f.b << std::endl;

    return 0;
}

