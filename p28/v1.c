#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, num, den;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // Calcula potencia y factorial de forma independiente en cada iteracion
        num = 1.0;
        for (j = 0; j < (2 * i); j++) num *= x;
        den = 1.0;
        for (j = 1; j <= (2 * i); j++) den *= j;
        suma += num / den;
    }

    printf("Resultado: %f\n", suma);
    return 0;
}