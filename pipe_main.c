#include <unistd.h> // For getpid()
#include <stdio.h> // For printf
#include <sys/wait.h> // For wait()

struct t {
    int seconds;
    int milli;
};

int main() {
    int filedes[2], read_fd, write_fd, pid;

    pipe(filedes);
    read_fd = filedes[0];
    write_fd = filedes[1];
    pid = fork();

    if(pid == 0) {
        close(read_fd);
        struct t t1 = {.seconds = 10 , .milli = 500};
        write(write_fd, &t1,sizeof(t1));
    }

    else {
        close(write_fd);
        struct t t0;
        read(read_fd, &t0, sizeof(t0));

        printf("Child results\n");
        printf("%d seconds %d milli-seconds\n",t0.seconds,t0.milli);
    }
    return 0;
}