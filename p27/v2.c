#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria = 0.0, numerador, denominador;

    /* agrega validacion do-while estricta para n iteraciones */
    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    for (i = 1; i <= n; i++) {
        exponente = 2 * i - 1;

        numerador = 1.0;
        for (j = 0; j < exponente; j++) numerador *= x;

        denominador = 1.0;
        for (j = 1; j <= exponente; j++) denominador *= j;

        /* ensamblaje eliminado, acumulacion directa de la fraccion */
        sumatoria += numerador / denominador;
    }

    printf("%lf\n", sumatoria);
    return 0;
}