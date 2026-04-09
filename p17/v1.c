#include <stdio.h>
#include <math.h>

int main (void){
    int n, k, i, j;
    int signo;
    double resultado = 0.0;
    double den;

    printf("Cantidad de iteraciones y valor de k: ");
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        // calcular signo con bucle
        signo = 1;
        for (j = 0; j < i; j++) {
            signo *= -1;
        }

        // calcular denominador con bucle
        den = 1.0;
        for (j = 0; j < (2*k+1); j++) {
            den *= (2*i + 1);
        }

        resultado += (double)signo / den;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}
