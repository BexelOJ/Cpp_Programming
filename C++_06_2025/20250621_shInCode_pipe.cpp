#include <cstdio>
#include <iostream>

int main() {
    FILE* pipe = popen("ps aux", "r");
    if (!pipe) {
        std::cerr << "Failed to run command\n";
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;
    }

    pclose(pipe);
    return 0;
}

