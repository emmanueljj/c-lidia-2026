#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, z, powz;

    printf("Ingrese x: ");
    scanf("%f", &x);
    printf("Ingrese n: ");
    scanf("%d", &n);

    z = (x - 1.0) / (x + 1.0);

    for (i = 0; i < n; i++) {
        // Calcula la potencia z^(2i+1)
        powz = 1.0;
        for (j = 0; j < (2 * i + 1); j++) {
            powz *= z;
        }
        suma += powz / (2.0 * i + 1.0);
    }

    printf("Resultado: %f\n", 2.0 * suma);
    return 0;
}