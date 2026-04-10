/*
 * Archivo: ln2_v1.c
 * Aproximacion de ln(2) con serie armonica alternada.
 * Nivel 1: Calculo por fuerza bruta generando el signo desde cero en cada iteracion.
 * * Detalles: 
 * Para cada termino de la sumatoria, se calcula el signo alterno 
 * (-1, 1, -1, 1...) multiplicando -1 repetidamente mediante un ciclo interno.
 */

#include <stdio.h>

int main(void) {
    int n, k, j;
    double ln2 = 0.0, num;

    /* Entrada de datos sin validacion  */
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    /* Bucle principal para la sumatoria */
    for (k = 1; k <= n; k++) {
        num = 1.0;
        j = 0;
        
        /* Ciclo interno: calcula el signo multiplicando -1 repetidamente */
        while (j < k + 1) {
            num *= -1.0;
            j++;
        }

        /* Suma del termino a la variable acumuladora */
        ln2 += num / k; 
    }

    /* Salida cruda del resultado */
    printf("%lf\n", ln2);

    return 0;
}