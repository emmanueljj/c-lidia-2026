#include <stdio.h>

double serie_arcsen(float x, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Producto incremental para estabilidad
        for (int j = 1; j <= i; j++) {
            fct *= (2.0 * j - 1.0) / (2.0 * j);
        }
        
        double px = 1.0;
        for (int j = 0; j < (2 * i + 1); j++) px *= x;
        
        suma += fct * (px / (2 * i + 1));
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

    printf("Resultado: %f\n", serie_arcsen(x, n));
    return 0;
}