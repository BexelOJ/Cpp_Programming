#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::unique_ptr<int> n(new int(10));
    std::cout << *n << std::endl;
    std::cout << n.get() << std::endl;
    return 0;
}


