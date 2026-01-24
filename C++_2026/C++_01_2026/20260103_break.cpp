#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << " i = " << i << std::endl;
        for (int j = 0; j < 5; j++) {
            if (j == 3) {
                break;
            }
            std::cout << " j = " << j << std::endl;
        }

    }
    return 0;
}


