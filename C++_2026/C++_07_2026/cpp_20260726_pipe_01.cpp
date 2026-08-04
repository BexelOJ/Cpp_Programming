#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    char msg[] = "Hello Pipe!";
    char buffer[100];

    // Write into the pipe
    write(fd[1], msg, strlen(msg) + 1);

    // Read from the pipe
    read(fd[0], buffer, sizeof(buffer));

    printf("Received: %s\n", buffer);

    close(fd[0]);
    close(fd[1]);

    return 0;
}

