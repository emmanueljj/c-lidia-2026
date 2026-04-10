/*
 * Archivo: senh_v1.c
 * Aproximacion de senh(x) con serie de Maclaurin.
 * Nivel 1: Implementacion directa recalculando potencia y factorial por termino.
 *
 * Detalles:
 * Se calculan la potencia y el factorial desde cero en cada iteracion
 * mediante el uso de ciclos anidados independientes. No se incluye 
 * estabilizacion numerica.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria = 0.0, numerador, denominador;

    printf("Ingrese n y x: ");
    scanf("%d %lf", &n, &x);

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 0; i < n; i++) {
        exponente = 2 * i + 1;

        /* Calcula potencia x^(2i+1) con ciclo while */
        numerador = 1.0;
        j = 0;
        while (j < exponente) {
            numerador *= x;
            j++;
        }

        /* Calcula factorial (2i+1)! con ciclo while */
        denominador = 1.0;
        j = 1;
        while (j <= exponente) {
            denominador *= j;
            j++;
        }

        /* Acumulacion directa del termino */
        sumatoria += numerador / denominador;
    }

    printf("S_n(x) = %lf\n", sumatoria);
    return 0;
}