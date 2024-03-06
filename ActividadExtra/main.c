#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main() {
    int fd;
    pid_t pid;
    int n;
    int valores[5]= {1, 2,3,4,5};
    pid=fork();

    if (pid==0){
        fd=creat("datos.txt", 777);

        n= write(fd, valores, sizeof(valores));
        close(fd);
        exit(0);
    }

    if(pid >0){
        sleep(2);
        fd = open("datos.txt", 0);

        n = read (fd, valores, sizeof(valores));

        close(fd);

        printf("Valores leidos: \n");
        for (int i; i < 5; i ++){
            printf("%d\n", valores[i]);
        }
        exit(0);
    }
}
