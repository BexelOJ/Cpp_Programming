#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::shared_ptr<int> m(new int(10));
    std::cout << *m << std::endl;
    return 0;
}




