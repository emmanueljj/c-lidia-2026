/*
 * Archivo: p7_v2.c
 * Aproximacion de e^x integrando estabilizacion de error (Epsilon).
 * Nivel 2: Incluye validacion de dominio y estructura for principal.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j;
    double x, resultado = 0.0, num, den, termino, epsilon = 1e-15;

    /* Validacion de dominio */
    do {
        printf("Ingrese el numero de iteraciones (n >= 0): ");
        scanf("%d", &n);
    } while (n < 0);

    printf("Ingrese valor de x: ");
    scanf("%lf", &x);

    /* Bucle principal con estructura for */
    for (i = 0; i <= n; i++) {
        num = 1.0;
        den = 1.0;
        j = 1;

        /* Ciclo interno combinando calculo de potencia y factorial con while */
        while (j <= i) {
            num *= x;
            den *= j;
            j++;
        }

        termino = num / den;

        /* Criterio de paro numérico */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
    }

    printf("%lf\n", resultado);

    return 0;
}