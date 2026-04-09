#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, u = 0.0, sumatoria = 1.0, numerador, denominador;

    /* validacion estricta de iteraciones minimas*/
    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    for (i = 1; i <= n; i++) {
        exponente = 2 * i - 1;

        numerador = 1.0;
        for (j = 0; j < exponente; j++) numerador *= x;

        denominador = 1.0;
        for (j = 1; j <= exponente; j++) denominador *= j;

        /* para alternar el signo */
        u += ((-1.0 + 2.0 * (i % 2)) * numerador) / denominador;
    }

    for (i = 1; i <= n; i++) {
        numerador = 1.0;
        for (j = 0; j < i; j++) numerador *= u;

        denominador = 1.0;
        for (j = 1; j <= i; j++) denominador *= j;

        /* acumulacion directa sin variables extra */
        sumatoria += numerador / denominador;
    }

    printf("%lf\n", sumatoria);
    return 0;
}