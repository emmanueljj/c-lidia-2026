/*
 * Archivo: p7_v1.c
 * Aproximacion de e^x con serie de Maclaurin.
 * Nivel 1: Calculo por separacion de variables.
 *
 * Detalles:
 * Para cada iteracion, se calcula la potencia y el factorial
 * desde cero mediante ciclos internos independientes.
 */

#include <stdio.h>

int main(void) {
    int n, i, j;
    double x, resultado = 0.0, num, den;

    /* Entrada de datos */
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);
    printf("Ingrese valor de x: ");
    scanf("%lf", &x);

    /* Bucle principal para la sumatoria */
    for (i = 0; i <= n; i++) {
        num = 1.0;
        for (j = 1; j <= i; j++) {
            num *= x;
        }

        den = 1.0;
        for (j = 1; j <= i; j++) {
            den *= j;
        }

        /* Acumulacion del termino */
        resultado += num / den;
    }

    /* Impresion del resultado final */
    printf("%lf\n", resultado);

    return 0;
}