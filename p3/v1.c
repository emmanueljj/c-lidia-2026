/*
 * Archivo: serie_basilea_v1.c
 * Aproximacion de pi^2 / 6 con la serie de Basilea.
 * Nivel 1: Calculo directo y secuencial sin validacion de dominio.
 * * Detalles: 
 * Para cada termino, se calcula el cuadrado del indice iterador (k * k)
 * en una variable auxiliar y se suma a la variable acumuladora.
 */

#include <stdio.h>

int main(void) {
    int n, k;
    double resultado = 0.0, den;

    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    /* Bucle principal para la sumatoria usando for */
    for (k = 1; k <= n; k++) {
        /* Calculo explicito del denominador */
        den = (double)(k * k);
                resultado += 1.0 / den; 
    }

    printf("%lf\n", resultado);

    return 0;
}