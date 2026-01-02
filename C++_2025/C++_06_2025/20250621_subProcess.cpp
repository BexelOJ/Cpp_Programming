#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>

int main() {
    pid_t pid1 = fork();
    std::cout<< "Parent (PID " << getpid() << ") created child 1." << std::endl;    
    sleep(3);
    if (pid1 < 0) {
        std::cerr << "Failed to fork first child." << std::endl;
        return 1;
    }

    if (pid1 == 0) {
        std::cout << "\nChild 1 (PID " << getpid() << ") exiting." << std::endl;
        std::cout << "Parent of Child 1 (PID " << getppid() << ") exiting.\n" << std::endl;
        sleep(3);
        exit(0);  // Exit only child 1
        std::cout<<"Child 1 exited"<<std::endl;  // will not print this line, after exit()
    }

    pid_t pid2 = fork();
    std::cout<< "Parent (PID " << getpid() << ") created child 2." << std::endl;
    sleep(3);
    if (pid2 < 0) {
        std::cerr << "Failed to fork second child." << std::endl;
        return 1;
    }

    if (pid2 == 0) {
        std::cout << "\nChild 2 (PID " << getpid() << ") exiting." << std::endl;
        std::cout << "Parent of Child 2 (PID " << getppid() << ") exiting.\n" << std::endl;
        sleep(3);   
        exit(0);  // Exit only child 2
    }

    // Only parent reaches here
    int status;

    wait(&status);  // Wait for one child
    std::cout << "Parent received exit status of child 1: " << WEXITSTATUS(status) << std::endl;

    wait(&status);  // Wait for the other child
    std::cout << "Parent received exit status of child 2: " << WEXITSTATUS(status) << std::endl;

    std::cout << "Parent (PID " << getpid() << ") done waiting for children." << std::endl;

    return 0;
}


