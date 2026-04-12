#include <stdio.h>

int main() {
    int n, i, j;
    float x, alpha;
    double suma = 0.0, powx, coef, fact;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese alpha: "); scanf("%f", &alpha);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // Calcula x^i y el coeficiente binomial desde cero
        powx = 1.0;
        for (j = 0; j < i; j++) powx *= x;

        coef = 1.0;
        fact = 1.0;
        for (j = 0; j < i; j++) {
            coef *= (alpha - j);
            fact *= (j + 1);
        }

        suma += (coef / fact) * powx;
    }

    printf("Resultado: %f\n", suma);
    return 0;
}