#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria, x_elevada;

    /* Validacion de dominio (|x| < 1) */
    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;

    for (i = 1; i <= n; i++) {
        exponente = 2 * i + 1;

        x_elevada = 1.0;
        for (j = 0; j < exponente; j++) x_elevada *= x;

        /*ensamblaje y acumulacion directa */
        sumatoria += x_elevada / exponente;
    }

    printf("%lf\n", sumatoria);
    return 0;
}