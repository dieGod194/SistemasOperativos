#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int array[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int subarray1[] = {1, 2, 3, 4};
int subarray2[] = {5, 6, 7, 8};
int subarray3[]= {9, 10, 11, 12};

int flag = 0;

int Snumber;

void* searcharray1( void *args )
{
    for(int i=0; i < 4; i++){
        if(subarray1[i] == Snumber){
            flag=1;
        }
    }
}

void* searcharray2( void *args )
{
    for(int i=0; i < 4; i++){
        if(subarray2[i] == Snumber){
            flag=2;
        }
    }
}

void* searcharray3( void *args )
{
    for(int i=0; i < 4; i++){
        if(subarray3[i] == Snumber){
            flag=3;
        }
    }
}

int main(void) {
    pthread_t thread_1, thread_2, thread_3; // ID del hilo
    int state1, state2, state3;

    printf("Ingresa un numero\n");
    scanf("%d", &Snumber);

    state1= pthread_create(&thread_1, NULL, searcharray1, NULL);
    state2= pthread_create(&thread_2, NULL, searcharray2, NULL);
    state3= pthread_create(&thread_3, NULL, searcharray3, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);

    if (flag==1){
        printf("Numero encontrado en el subarreglo 1\n");
    } else if (flag==2){
        printf("Numero encontrado en el subarreglo 2\n");
    } else if (flag==3){
        printf("Numero encontrado en el subarreglo 3\n");
    } else{
        printf("No se encontro el numero :(\n");
    }
    return 0;
}
