#include <stdio.h>
#include <stdbool.h>

//Functions
// find the next prime number
int prime_number(int number)
{
    int holder=number;

    while (tre)
    {


        if (number%2==0)
        {
            number+=1;
        }

        else if (number%3==0)
        {
            number+=1;
        }

        else if (number%5==0)
        {
            number+=1;
        }

        else if (number%7==0)
        {
            number+=1;
        }
        else {
            return printf("El siguiente numero primo de %d es: %d\n", holder, number);
            break;
        }
    }
}

//Does the factorial operation of the number
int factorial(int number)
{
    int result=1;
    int i = 1;
    while(i<=number)
    {
        result= i * result;
        i++;
    }
    return printf("El factorial del numero es: %d\n", result);
}
int main() {
    int option;
    int input;
    printf("Ingresa un numero:\n");
    scanf("%d", &input);
    printf("Que quieres hacer con el numero?\n 1- Sacar factorial\n 2- Encontrar el siguiente numero primo\n");
    scanf("%d", &option);
    if (option==1)
    {
        return factorial(input);
    }
    else if (option==2)
    {
        return prime_number(input);
    }
    else
    {
        printf("error");
    }
}

