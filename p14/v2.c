#include <stdio.h>

double serie_ej14(float x, float alpha, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double termino = 1.0;
        // Producto incremental para el coeficiente y la potencia
        for (int j = 0; j < i; j++) {
            termino *= (x * (alpha - j) / (j + 1));
        }
        suma += termino;
    }
    return suma;
}

int main() {
    float x, alpha;
    int n;

    do { // Validacion de dominio
        printf("Ingrese x (-1 < x < 1): ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);

    printf("Ingrese alpha: ");
    scanf("%f", &alpha);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_ej14(x, alpha, n));
    return 0;
}