#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child
        close(fd[1]);          // Close write end

        char buffer[100];

        read(fd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }
    else
    {
        // Parent
        close(fd[0]);          // Close read end

        char msg[] = "Hello from Parent";

        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);

        wait(NULL);
    }

    return 0;
}

