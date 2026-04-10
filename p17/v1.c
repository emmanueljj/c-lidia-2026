/*
 * Archivo: v1.c
 * Aproximacion de la sumatoria parcial de los Numeros de Euler.
 * Nivel 1: Calculo directo de signo y denominador.
 *
 * Detalles:
 * Para cada iteracion, se calcula el signo alterno y el denominador
 * mediante ciclos internos independientes.
 */
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
        /* Calcular signo iterativamente */
        signo = 1;
        j = 0;
        while (j < i) {
            signo *= -1;
            j++;
        }

        /* Calcular denominador iterativamente */
        den = 1.0;
        j = 0;
        while (j < (2*k+1)) {
            den *= (2*i + 1);
            j++;
        }

        resultado += (double)signo / den;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}