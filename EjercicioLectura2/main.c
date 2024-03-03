#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    float fd;
    int m;
    int i;
    int valuesR[5];

    fd= open("C:\\Users\\Jugge\\CLionProjects\\EjercicioLecturaPrintN\\cmake-build-debug\\datos2.txt", 0);

    m = read(fd, valuesR, sizeof(valuesR));

    printf("Valores leidos: \n");

    for(i = 0; i < 5; i++) {
        printf("%f\n", &valuesR[i]);
    }

    close(fd);

    return 0;
}