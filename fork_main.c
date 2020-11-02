#include <unistd.h> // For getpid()
#include <stdio.h> // For printf
#include <sys/wait.h> // For wait()

int main() {
    int process = fork();
    int exit, status, parent = 0, child = 0;

    parent = wait(NULL);
    parent = child = getpid();

    printf("Child Process PID is %d\n", child);
    printf("I'm the parent. Their PID is %d\n", parent);
    exit = WEXITSTATUS(status);
    printf("Child status is %d\n", exit);

    return 0;
}
