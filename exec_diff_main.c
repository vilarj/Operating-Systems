#include <unistd.h> // For getpid()
#include <stdio.h> // For printf
#include <sys/wait.h> // For wait()

int main(int argc, char* argv[]) {
    char *files[2];

    files[0] = argv[1];
    files[1] = argv[2];

    if ( (files[0] && files[1]) != NULL) {
        int status;
        char *args[] = {"/usr/bin/diff", "-q", files[0], files[1], NULL};

        if (fork() == 0) {
            int ret = execv(args[0], args);
            exit(ret);
        }

        else {
            wait(&status);
            status = WEITSTATUS(status);

            if (status == 0) {
                printf("Files are equal\n");
            }
            else {
                printf("Files are not equal\n");
            }
        }
    }

    else {
        printf("./exec_diff_main needs 2 arguments\n");
    }

    return 0;
}


