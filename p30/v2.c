#include <stdio.h>

double serie_arcsenh(float x, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double coef = 1.0;
        // Simplificacion: (2n)! / (4^n * (n!)^2) = producto de (2j-1)/(2j)
        for (int j = 1; j <= i; j++) {
            coef *= (2.0 * j - 1.0) / (2.0 * j);
        }
        
        double px = 1.0;
        for (int j = 0; j < (2 * i + 1); j++) px *= x;
        
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += signo * coef * (px / (2.0 * i + 1.0));
    }
    return suma;
}

int main() {
    float x; int n;
    do {
        printf("Ingrese x (|x| < 1): ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_arcsenh(x, n));
    return 0;
}