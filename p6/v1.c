#include <stdio.h>

int main() {
    int n, i;
    double suma = 0.0;

    printf("Ingrese n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        // Implementacion directa de la formula
        suma += 1.0 / (i * (i + 2.0));
    }

    printf("S_%d = %f\n", n, suma);
    return 0;
}