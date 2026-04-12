#include <stdio.h>

int main() {
    int n, i;
    double suma = 0.0, impar;

    printf("Ingrese n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // Calcula el cuadrado
        impar = 2.0 * i + 1.0;
        suma += 1.0 / (impar * impar);
    }

    printf("Resultado: %f\n", suma);
    return 0;
}