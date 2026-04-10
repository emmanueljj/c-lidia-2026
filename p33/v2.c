/*
 * Archivo: v2.c
 * Aproximacion de e^(sen(x)) con serie de Maclaurin.
 * Nivel 2: Inclusion de validacion de dominio y estabilizacion numerica.
 *
 * Detalles:
 * Se restringe la cantidad de iteraciones (n >= 1). Se integra
 * un criterio de paro (epsilon) en ambas sumatorias para detener los
 * ciclos si la precision ya es suficiente. Los bucles principales 
 * utilizan for y las iteraciones internas while.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j, exponente;
    double x, u = 0.0, sumatoria = 1.0, numerador, denominador, termino;
    double epsilon = 1e-8;

    /* validacion estricta de iteraciones minimas */
    do {
        printf("Ingrese n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    /* Bucle principal para calcular u = sen(x) (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        exponente = 2 * i - 1;

        numerador = 1.0;
        j = 0;
        while (j < exponente) {
            numerador *= x;
            j++;
        }

        denominador = 1.0;
        j = 1;
        while (j <= exponente) {
            denominador *= j;
            j++;
        }

        /* para alternar el signo */
        termino = ((-1.0 + 2.0 * (i % 2)) * numerador) / denominador;

        if (fabs(termino) < epsilon) {
            break;
        }

        u += termino;
    }

    /* Bucle principal para calcular e^u (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        numerador = 1.0;
        j = 0;
        while (j < i) {
            numerador *= u;
            j++;
        }

        denominador = 1.0;
        j = 1;
        while (j <= i) {
            denominador *= j;
            j++;
        }

        /* acumulacion directa sin variables extra */
        termino = numerador / denominador;

        if (fabs(termino) < epsilon) {
            break;
        }

        sumatoria += termino;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}