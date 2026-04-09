#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria = 0.0, numerador, denominador;

    scanf("%d %lf", &n, &x);

    /*bucle principal*/
    for (i = 1; i <= n; i++) {
        exponente = 2 * i - 1;

        /*calcula potencias*/
        numerador = 1.0;
        for (j = 0; j < exponente; j++) numerador *= x;

        /*calcula factoriales*/
        denominador = 1.0;
        for (j = 1; j <= exponente; j++) denominador *= j;

        sumatoria += numerador / denominador;
    }

    printf("%lf\n", sumatoria);
    return 0;
}