#include <stdio.h>

double serie_ej8(float x, int n) {
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double fct = 1.0;
        // Producto incremental para manejar la precision
        for (int j = 1; j <= i; j++) {
            fct *= (x / j);
        }
        suma += i * fct;
    }
    return suma;
}

int main() {
    float x;
    int n;

    printf("Ingrese x: ");
    scanf("%f", &x);
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_ej8(x, n));
    return 0;
}