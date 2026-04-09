#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double x, sumatoria, x_elevada, x_cuadrada;

    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;
    
    x_elevada = x;
    x_cuadrada = x * x;

    for (i = 1; i <= n; i++) {
        x_elevada *= x_cuadrada;
        sumatoria += x_elevada / (2.0 * i + 1.0);
    }

    printf("%lf\n", sumatoria);
    return 0;
}