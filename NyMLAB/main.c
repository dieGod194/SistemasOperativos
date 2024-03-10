#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int arrayTemp[10];
    int arrayTemp2[10];
    int arrayR[10];
    
    int fd, fd2;
    int n, m;

    pid_t pidm;
    pid_t pidn;

    pidn = fork();

    if (pidn==0){
        int evenarray[10]= {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

        fd = creat ("n.txt", 777);

        n= write(fd, &evenarray, sizeof(evenarray));
        close(fd);

        exit(0);
    }

    pidm=fork();

    if (pidm==0){
        int oddarray[10]= {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

        fd = creat ("m.txt", 777);

        n= write(fd, &oddarray, sizeof(oddarray));
        close(fd);

        exit(0);
    }

    sleep(4);

    fd = open("n.txt", 0);
    fd2 = open("m.txt", 0);

    for (int i = 0; i<10; i++){
        read(fd, &arrayTemp[i], sizeof(arrayTemp[0]));
        read(fd2, &arrayTemp2[i], sizeof(arrayTemp2[0]));

        arrayR[i] = arrayTemp[i] + arrayTemp2[i];
    }

    printf("Suma de ambos arreglos: ");

    for (int i = 0; i < 10; i++) {
        printf("%d", arrayR[i]);
        if (i != 9) {
            printf(", ");
        }
    }

    printf("\n");


}
