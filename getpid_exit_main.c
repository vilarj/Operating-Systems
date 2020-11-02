#include <unistd.h> // For getpid()
#include <stdio.h> // For printf

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("-------------\n");
        printf("ERROR: Pid is 0\n");
        printf("-------------\n");
    }

    else if (pid == 0) {
        printf("-------------\n");
        printf("My PID is %d\n", getpid());
        printf("-------------\n");
    }

    else {
        printf("-------------\n");
        printf("Getting PID %d\n", getpid());
    }

    return 0;
}
