#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, armónico, px;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        // Calcula el numero armonico
        armónico = 0.0;
        for (j = 1; j <= i; j++) {
            armónico += 1.0 / j;
        }

        // Calcula x^i
        px = 1.0;
        for (j = 0; j < i; j++) {
            px *= x;
        }

        // Alternancia de signo y suma
        if (i % 2 == 0) suma -= armónico * px;
        else suma += armónico * px;
    }

    printf("Resultado: %f\n", suma);
    return 0;
}