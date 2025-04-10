#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";

    std::cout << "Size: " << s.size() << std::endl;
    std::cout << "Capacity: " << s.capacity() << std::endl;

    s += " this is a longer string";

    std::cout << "New Size: " << s.size() << std::endl;
    std::cout << "New Capacity: " << s.capacity() << std::endl;

    return 0;
}

/*
Output:

Size: 5
Capacity: 15
New Size: 29
New Capacity: 30

*/