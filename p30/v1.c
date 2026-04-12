#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, num, den, px, p4;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // Factorial de (2i)
        num = 1.0;
        for (j = 1; j <= (2 * i); j++) num *= j;

        // (i!)^2
        den = 1.0;
        for (j = 1; j <= i; j++) den *= j;
        den = den * den;
        
        // 4^i
        p4 = 1.0;
        for (j = 0; j < i; j++) p4 *= 4.0;
        
        // x^(2i+1)
        px = 1.0;
        for (j = 0; j < (2 * i + 1); j++) px *= x;

        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += signo * (num * px) / (p4 * den * (2.0 * i + 1.0));
    }

    printf("Resultado: %f\n", suma);
    return 0;
}