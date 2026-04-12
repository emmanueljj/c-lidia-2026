#include <stdio.h>

double serie_ln(float x, int n) {
    double suma = 0.0;
    double z = (x - 1.0) / (x + 1.0);

    for (int i = 0; i < n; i++) {
        double powz = 1.0;
        for (int j = 0; j < (2 * i + 1); j++) powz *= z;
        
        suma += powz / (2.0 * i + 1.0);
    }
    return 2.0 * suma;
}

int main() {
    float x;
    int n;

    // Validacion de dominio x > 0
    do {
        printf("Ingrese x (x > 0): ");
        scanf("%f", &x);
    } while (x <= 0);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_ln(x, n));
    return 0;
}