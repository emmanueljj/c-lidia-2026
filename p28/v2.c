#include <stdio.h>

double serie_cosh(float x, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental para mejorar la estabilidad ante numeros grandes
        for (int j = 1; j <= (2 * i); j++) {
            fct *= (x / j);
        }
        suma += fct;
    }
    return suma;
}

int main() {
    float x; int n;
    printf("Ingrese x: "); scanf("%f", &x);
    do {
        printf("Ingrese n: "); scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_cosh(x, n));
    return 0;
}