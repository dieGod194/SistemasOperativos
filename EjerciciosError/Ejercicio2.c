#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int error_comp(int fd, int n) {
    if (fd < 0) {
        if (errno == EAGAIN) {
            printf("Archivo bloqueado.\n");
            exit(1);
        } else if (errno == EACCES) {
            printf("Problema de permisos del archivo.\n");
            exit(1);
        } else if (errno == EBADF) {
            printf("Mal descriptor del archivo.\n");
            exit(1);
        } else {
            printf("Error desconocido.\n");
            exit(1);
        }
    }
}


int main() {
    float fd;
    int n;
    int i;
    int values[5];

    fd = creat("datos.txt", 777);

    error_comp(fd, n);

    printf("Ingresa los 5 numeros que quieres escribir en tu txt\n");
    for(i = 0; i < 5; i++) {
        scanf("%f", &values[i]);
    }

    n = write(fd, values, sizeof(values));
    error_comp(fd, n);

    close(fd);

    return 0;
}
