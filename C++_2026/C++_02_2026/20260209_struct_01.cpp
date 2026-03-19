#include <iostream>
#include <string>

struct person {
    std::string name;
    int age;
};

int main() {
    person p1, p2, p3;
    p1.name = "Arun";
    p1.age = 25;

    p2.name = "Madhu";
    p2.age = 32;

    std::cout << "Name : " << p1.name << std::endl;
    std::cout << "Age : "  << p1.age << std::endl;

    std::cout << "Name : " << p2.name << std::endl;
    std::cout << "Age : " << p2.age << std::endl;

    return 0;
}


