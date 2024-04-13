#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int array[]= {0, 0, 0, 0, 0};
int flag=0;

void* reader(void* args) {
    while (1) {
        for (int e = 0; e < sizeof(array); e++) {
            if (array[e] != 0) {
                printf("Numero leido: %d\n", array[e]);
                array[e] = 0;
                if(e==4){
                    pthread_exit( NULL );
                }
            }
        }
    }
}

int main(void) {
    pthread_t thread;
    int state, input;

    state= pthread_create(&thread, NULL, reader, NULL);

    for(int i = 0; i<sizeof(array); i++){
        sleep(1);
        printf("Ingresa un numero:\n");
        scanf("%d", &input);
        array[i] = input;
    }

    flag= 1;

    pthread_join(thread, NULL);

    printf("Hemos terminado\n");

    return 0;
}
