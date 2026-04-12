#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, num, den, px;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 0; i < n; i++) {
        num = 1.0;
        den = 1.0;
        // Producto de impares y pares (doble factorial)
        for (j = 1; j <= i; j++) {
            num *= (2.0 * j - 1.0);
            den *= (2.0 * j);
        }
        
        px = 1.0;
        for (j = 0; j < (2 * i + 1); j++) px *= x;

        suma += (num / den) * (px / (2.0 * i + 1.0));
    }

    printf("Resultado: %f\n", suma);
    return 0;
}