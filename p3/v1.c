
#include <stdio.h>

int main(void)
{
    int n, k, j,den;
    float resultado = 0.0f;

    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        den = k*k;
        resultado += (float) 1 / den; 
    }

    printf("resultado: %f\n", resultado);

    return 0;
}
