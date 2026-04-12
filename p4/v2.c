#include <stdio.h>

double serie_pi8(int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double impar = 2.0 * i + 1.0;
        suma += 1.0 / (impar * impar);
    }
    return suma;
}

int main() {
    int n;
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_pi8(n));
    return 0;
}