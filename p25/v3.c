#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double x, sumatoria, fraccion_acumulada, x_elevada, termino_listo;

    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;
    
     /*se usa un solo ciclo*/
    fraccion_acumulada = 1.0;
    x_elevada = x;

    for (i = 1; i <= n; i++) {
        /* Cambio 3: Actualizacion matematica in-line sin bucles 'for' */
        fraccion_acumulada *= (2.0 * i - 1.0) / (2.0 * i);
        x_elevada *= (x * x);

        sumatoria += fraccion_acumulada * (x_elevada / (2.0 * i + 1.0));
    }

    printf("%lf\n", 1.5707963267948966 - sumatoria);
    return 0;
}