/*
 * Archivo: serie_basilea_v2.c
 * Aproximacion de pi^2 / 6 estabilizando el error (Epsilon).
 * Nivel 2: Se incluye validacion estricta de dominio, criterio de paro numerico,
 * y se cambia el bucle principal a un for (Regla de oro).
 */

#include <stdio.h>

int main(void) {
    int n, k;
    double resultado = 0.0, termino, epsilon = 1e-12;

    /* Validacion de dominio (n debe ser al menos 1) */
    do {
        printf("Ingrese el numero maximo de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Bucle principal con estructura for */
    for (k = 1; k <= n; k++) {
        termino = 1.0 / ((double)k * k);

        /* Criterio de paro numerico */
        if (termino < epsilon) {
            break;
        }

        /* Acumulacion del termino */
        resultado += termino;
    }

    printf("%lf\n", resultado);

    return 0;
}