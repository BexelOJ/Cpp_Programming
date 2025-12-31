#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) { // child
        printf("CHILD: pid=%d ppid=%d\n", getpid(), getppid());
        fflush(stdout);
        sleep(60); // keep child alive
    }
    else {       // parent
        printf("PARENT: pid=%d child=%d\n", getpid(), pid);
        fflush(stdout);
        sleep(60); // keep parent alive
    }
}


