#include <stdio.h>

double serie_ej6(int n) {
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        suma += 1.0 / (i * (i + 2.0));
    }
    return suma;
}

int main() {
    int n;
    do {
        printf("Ingrese n (n > 0): ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_ej6(n));
    return 0;
}