
#include <stdio.h>

int main(void)
{
    int n, k,den;
    float resultado = 0.0f;

    /*se implementa validacion*/
    do{
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    } while (n<0);
    

    for (k = 1; k <= n; k++) {
        den = k*k;
        resultado += (float) 1 / den; 
    }

    printf("resultado: %f\n", resultado);

    return 0;
}
