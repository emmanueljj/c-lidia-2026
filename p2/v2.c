
#include <stdio.h>

int main(void)
{
    int n, k, j, signo; /*se evita usar variabla para denominador*/
    float ln2 = 0.0f;

    /*se implementa validacion*/
    do{
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    } while (n<0);
    

    for (k = 0; k <= n+1; k++) {
     signo = -1; 

        for (j = 0; j < k + 1; j++) {
         signo *= -1;
        }

        ln2 += (float) signo / (2*k+1); /*El denominador se calcula dento de ln2*/
    }

    printf("resultado: %f\n", ln2);

    return 0;
}