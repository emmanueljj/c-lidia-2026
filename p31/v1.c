#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, sumatoria, x_elevada;

    scanf("%d %lf", &n, &x);

    sumatoria = x;

    /*bucle principal*/
    for (i = 1; i <= n; i++) {
        exponente = 2 * i + 1;

        /*calcula potencias de x*/
        x_elevada = 1.0;
        for (j = 0; j < exponente; j++) {
            x_elevada *= x;
        }

        sumatoria += x_elevada / exponente;
    }

    printf("%lf\n", sumatoria);
    return 0;
}