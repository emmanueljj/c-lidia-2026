/*
 * Archivo: serie_medios_v2.c
 * Aproximacion de 1/2 integrando estabilizacion de error (Epsilon).
 * Nivel 2: Incluye validacion de dominio y estructura for principal.
 */

#include <stdio.h>

int main(void) {
    int n, i;
    double resultado = 0.0, termino, epsilon = 1e-12;

    /* Validacion de dominio */
    do {
        printf("Ingrese el numero maximo de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Bucle principal con estructura for */
    for (i = 0; i < n; i++) {
        termino = 1.0 / ((2.0 * i + 1.0) * (2.0 * i + 3.0));

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