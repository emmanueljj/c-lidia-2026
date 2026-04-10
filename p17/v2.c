/*
 * Archivo: v2.c
 * Aproximacion de la sumatoria parcial de los Numeros de Euler.
 * Nivel 2: Incluye validacion de dominio, estabilizacion numerica (Epsilon)
 * y estructura for principal.
 *
 * Detalles:
 * Se restringe la entrada asegurando valores validos para n y k.
 * El ciclo principal evalua la sumatoria con for, y el ciclo interno 
 * calcula la potencia del denominador con while.
 */
#include <stdio.h>
#include <math.h>

int main (void){
    int n, k, i, j;
    double resultado = 0.0, termino;
    double den;
    double epsilon = 1e-8;

    /* Validacion de dominio estricta */
    do{
        printf("Cantidad de iteraciones y valor de k: ");
        scanf("%d %d", &n, &k);    
    } while (n < 1 || k < 0);
    
    /* Ciclo iterativo principal con for (Regla de oro) */
    for (i = 0; i < n; i++) {
        
        /* Calcular denominador con bucle while */
        den = 1.0;
        j = 0;
        while (j < (2 * k + 1)) {
            den *= (2.0 * i + 1.0);
            j++;
        }

        /* Se genera el termino con alternancia de signo deductiva */
        termino = (double)(1 - 2 * (i % 2)) / den;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        /* Acumulacion del resultado */
        resultado += termino;
    }

    printf("Resultado: %lf\n", resultado);
    return 0;
}