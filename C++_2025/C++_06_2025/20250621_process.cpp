#include <iostream>
#include <unistd.h>  // For getpid()
#include <sys/types.h>

int main() {
    pid_t pid = getpid();  // Get current process ID
    sleep(5);
    std::cout << "Current Process ID: " << pid << std::endl;
    fork();
    return 0;
}

