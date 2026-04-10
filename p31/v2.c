/*
 * Archivo: v2.c
 * Aproximacion de arctanh(x) con serie de Maclaurin.
 * Nivel 2: Inclusion de validacion de dominio y estabilizacion numerica.
 *
 * Detalles:
 * Se restringe la entrada iterativa y el dominio de convergencia (|x| < 1).
 * Se integra un criterio de paro (epsilon) para detener el ciclo. 
 * El bucle principal utiliza for y la potencia se calcula con while.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria, x_elevada, termino;
    double epsilon = 1e-8;

    /* Validacion de dominio (|x| < 1) */
    do {
        printf("Ingrese n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        exponente = 2 * i + 1;

        /* calculo de potencia con while */
        x_elevada = 1.0;
        j = 0;
        while (j < exponente) {
            x_elevada *= x;
            j++;
        }

        termino = x_elevada / exponente;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        sumatoria += termino;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}