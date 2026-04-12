#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, px;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // Calcula la potencia x^(2i+1) manualmente
        px = 1.0;
        for (j = 0; j < (2 * i + 1); j++) {
            px *= x;
        }

        if (i % 2 == 0) suma += px / (2 * i + 1);
        else suma -= px / (2 * i + 1);
    }

    printf("Resultado: %f\n", suma);
    return 0;
}