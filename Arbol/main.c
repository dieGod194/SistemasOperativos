#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pidT, pidW, pidV, pidL, pidS, pidP;

    pidT = fork();

    if (pidT == 0) {
        printf("Soy T, mi id es: %d\n", getpid());
        printf("El id de mi padre es: %d\n", getppid());

        pidV = fork();

        if (pidV == 0) {
            printf("Soy V, mi id es: %d\n", getpid());
            printf("El id de mi padre es: %d\n", getppid());
            exit(0);
        }

        exit(0);
    }

    pidW = fork();

    if (pidW == 0) {
        printf("Soy W, mi id es: %d\n", getpid());
        printf("El id de mi padre es: %d\n", getppid());

        pidS = fork();

        if (pidS == 0) {
            printf("Soy S, mi id es: %d\n", getpid());
            printf("El id de mi padre es: %d\n", getppid());
            exit(0);
        }

        pidL = fork();

        if (pidL == 0) {
            printf("Soy L, mi id es: %d\n", getpid());
            printf("El id de mi padre es: %d\n", getppid());

            pidP = fork();

            if (pidP == 0) {
                printf("Soy P, mi id es: %d\n", getpid());
                printf("El id de mi padre es: %d\n", getppid());
                exit(0);
            }

            exit(0);
        }

        exit(0);
    }

    sleep(3);
}