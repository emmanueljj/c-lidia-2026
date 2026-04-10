/*
 * Archivo: v2.c
 * Aproximacion de arc cos(x) con serie de Maclaurin.
 * Nivel 2: Incluye validacion de dominio y reduccion de ciclos internos.
 *
 * Detalles:
 * Se restringe la entrada al dominio de convergencia (|x| < 1).
 * Los productos de numeradores y denominadores se calculan simultaneamente 
 * en un solo ciclo while interno.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j;
    double x, sumatoria, prod_impar, prod_par, x_elevada;

    /* Validacion de dominio (|x| < 1) */
    do {
        printf("Introduce el valor para n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;

    /* Bucle principal (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        prod_impar = 1.0;
        prod_par = 1.0;
        
        /* Ciclo combinado con while */
        j = 1;
        while (j <= i) {
            prod_impar *= (2.0 * j - 1.0);
            prod_par *= (2.0 * j);
            j++;
        }    

        /* Ciclo para potencias con while */
        x_elevada = 1.0;
        j = 0;
        while (j < (2 * i + 1)) {
            x_elevada *= x;
            j++;
        }

        sumatoria += (prod_impar / prod_par) * (x_elevada / (2.0 * i + 1.0));
    }

    printf("%lf\n", 1.5707963267948966 - sumatoria);
    return 0;
}