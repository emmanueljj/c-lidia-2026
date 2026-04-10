/*
 * Archivo: v2.c
 * Aproximacion de sen(x) con serie de Maclaurin.
 * Nivel 2: Incluye validacion de dominio, estabilizacion numerica (Epsilon) 
 * y calculo consolidado.
 *
 * Detalles:
 * Se valida la entrada de iteraciones. El numerador (que absorbe la 
 * alternancia de signo) y el denominador se calculan simultaneamente 
 * dentro de un ciclo interno while.
 */
#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j;
    double resultado = 0.0, den, num, x, termino;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do {   
        printf("Cantidad de iteraciones y valor de x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    /* Ciclo principal con estructura for (Regla de oro) */
    for (i = 0; i <= n; i++) {
        num = (1 - 2 * (i % 2));
        den = 1.0;
        
        /* calculo de numerador y denominador simultaneo con while */
        j = 1;
        while (j <= 2 * i + 1) {
            num *= x;
            den *= j;
            j++;
        }   

        termino = num / den;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}