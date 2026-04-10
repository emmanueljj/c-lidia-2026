/*
 * Archivo: ln2_v2.c
 * Aproximacion de ln(2) estabilizando el error (Epsilon).
 * Nivel 2: Se incluye validacion de dominio, alternancia progresiva del signo 
 * y se cambia el bucle principal a un for (Regla de oro).
 */

#include <stdio.h>

int main(void) {
    int n, k;
    double ln2 = 0.0, termino, signo = 1.0, epsilon = 1e-8;

    /* Validacion estricta de dominio */
    do {
        printf("Ingrese el numero maximo de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Ciclo principal iterando con for (Regla de oro) */
    for (k = 1; k <= n; k++) {
        termino = 1.0 / k;

        /* Criterio de paro numérico: Si el termino ya no aporta valor, se rompe el ciclo */
        if (termino < epsilon) {
            break;
        }

        /* Ensamblaje del termino y acumulacion */
        ln2 += signo * termino;
        
        /* Alternancia eficiente del signo sin bucles internos */
        signo *= -1.0; 
    }

    /* Salida cruda del resultado */
    printf("%lf\n", ln2);

    return 0;
}