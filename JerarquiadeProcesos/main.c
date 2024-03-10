#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    pid_t pidA, pidB, pidM;
    int status, contador;
    int n =3;

    pidA = fork();

    if (pidA==0){
        printf("Mi id de hijo es: %d\n", getpid());
        return(0);
    }

    pidB=fork();

    if (pidB==0){
        printf("Mi id de hijo es: %d\n", getpid());

        return(0);
    }

    pidM=fork();

    if (pidM==0){
        printf("Mi id de hijo es: %d\n", getpid());

        return(0);
    }

    if (pidM>0 && pidB>0 && pidA>0){

        for(int i =0; i<n; i++){
            wait (&status);
            if(WEXITSTATUS(status) ==0){
                contador++;
            }
        }

        if(contador==3){
            printf("procesos terminados con exito: %d \n", contador);

        }

    }



}
