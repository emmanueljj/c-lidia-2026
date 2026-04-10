/*
 * Archivo: senh_v2.c
 * Aproximacion de senh(x) con serie de Maclaurin.
 * Nivel 2: Inclusion de validacion de dominio y estabilizacion de la solucion.
 *
 * Detalles:
 * Se restringe la entrada de iteraciones (n >= 1). Se integra un 
 * criterio de paro basado en una tolerancia (epsilon) para detener 
 * el bucle si el termino calculado ya no aporta precision significativa.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria = 0.0, numerador, denominador, termino;
    double epsilon = 1e-8; /* Tolerancia de estabilizacion */

    /* Validacion de entrada de iteraciones */
    do {
        printf("Ingrese n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 0; i < n; i++) {
        exponente = 2 * i + 1;

        /* Ciclo interno con while para la potencia */
        numerador = 1.0;
        j = 0;
        while (j < exponente) {
            numerador *= x;
            j++;
        }

        /* Ciclo interno con for para el factorial */
        denominador = 1.0;
        for (j = 1; j <= exponente; j++) {
            denominador *= j;
        }

        termino = numerador / denominador;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        sumatoria += termino;
    }

    printf("S_n(x) = %lf\n", sumatoria);
    return 0;
}