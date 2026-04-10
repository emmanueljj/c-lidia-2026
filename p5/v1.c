/*
 * Archivo: serie_medios_v1.c
 * Aproximacion de 1/2 mediante serie de fracciones.
 * Nivel 1: Calculo por separacion de variables.
 *
 * Detalles:
 * Para cada iteracion, se calculan los factores (2i+1) y (2i+3),
 * se multiplican para obtener el denominador y se divide para sumar al acumulador.
 */

#include <stdio.h>

int main(void) {
    int n, i, denominador;
    double resultado = 0.0;

    /* Entrada de datos */
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    /* Bucle principal para la sumatoria */
    for (i = 0; i < n; i++) {
        denominador = (2 * i + 1) * (2 * i + 3);
        resultado += 1.0 / denominador;
    }

    /* Impresion del resultado final */
    printf("%lf\n", resultado);

    return 0;
}