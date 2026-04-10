/*
 * Archivo: v1.c
 * Aproximacion de arctanh(x) con serie de Maclaurin.
 * Nivel 1: Calculo de componentes mediante ciclos independientes.
 *
 * Detalles:
 * En cada iteracion del bucle principal for, se calcula la potencia de x
 * desde cero empleando un ciclo interno while.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria, x_elevada;

    printf("Ingrese n y x: ");
    scanf("%d %lf", &n, &x);

    sumatoria = x;

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        exponente = 2 * i + 1;

        /* calcula potencias de x con while */
        x_elevada = 1.0;
        j = 0;
        while (j < exponente) {
            x_elevada *= x;
            j++;
        }

        sumatoria += x_elevada / exponente;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}