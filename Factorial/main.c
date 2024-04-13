#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int numero;
int memoriatemp;
int factorialpt1 = 1;
int factorialpt2 =1;
int factorialpt3=1;



void* factorial1( void *args )
{
    memoriatemp= numero/3;
    int i = 1;
    while (i<=memoriatemp){
        factorialpt1= factorialpt1*i;
        i++;
    }
}

void* factorial2( void *args )
{
    memoriatemp= (numero/3 * 2);
    int i = (numero/3);
    while (i<=memoriatemp){
        factorialpt2= factorialpt2*i;
        i++;
    }
}

void* factorial3( void *args )
{
    memoriatemp= numero;
    int i = (numero/3 *2);
    while (i<=memoriatemp){
        factorialpt3= factorialpt3*i;
        i++;
    }
}

int main() {
    pthread_t thread_1, thread_2, thread_3; // ID del hilo
    int state1, state2, state3;
    int result;

    printf("Ingresa un numero divisible entre 3\n");
    scanf("%d", &numero);

    if(numero%3==0){

        state1 = pthread_create( &thread_1, NULL, &factorial1, NULL );
        state2 = pthread_create( &thread_2, NULL, &factorial2, NULL );
        state3 = pthread_create( &thread_3, NULL, &factorial3, NULL );
        pthread_join(thread_1, NULL);
        pthread_join(thread_2, NULL);
        pthread_join(thread_3, NULL);

        result= factorialpt1*factorialpt2*factorialpt3;

        printf("El factorial es: %d\n", result);

    } else {
        printf("Ingresa un numero divisible entre 3\n");
        scanf("%d", &numero);
    }
    return 0;
}
