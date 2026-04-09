#include <stdio.h>

int main(void) {
    int n, i;
    double x, u, sumatoria = 1.0;
    double termino_sin, x_cuadrada, termino_exp;

    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    termino_sin = x;
    x_cuadrada = x * x;
    u = x;

    for (i = 1; i < n; i++) {
        /*recurrencia saltando impares. signo alterno se genera solo con el negativo de x_cuadrada*/
        termino_sin *= -x_cuadrada / ((2.0 * i) * (2.0 * i + 1.0));
        u += termino_sin;
    }

    /*inicializacion para la serie */
    termino_exp = 1.0;

    for (i = 1; i <= n; i++) {
        /* recurrencia in-line multiplicando fluidamente por u/i*/
        termino_exp *= u / i;
        sumatoria += termino_exp;
    }

    printf("%lf\n", sumatoria);
    return 0;
}