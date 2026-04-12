#include <stdio.h>

double serie_ln(float x, int n) {
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double num = 1.0;
        for (int j = 0; j < i; j++) num *= x;
        
        double signo = (i % 2 == 0) ? -1.0 : 1.0;
        suma += (signo * num) / i;
    }
    return suma;
}

int main() {
    float x;
    int n;

    // Validacion de dominio segun el PDF  -1 < x <= 1
    do {
        printf("Ingrese x (-1 < x <= 1): ");
        scanf("%f", &x);
    } while (x <= -1.0 || x > 1.0);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_ln(x, n));
    return 0;
}