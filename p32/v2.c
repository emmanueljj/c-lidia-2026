#include <stdio.h>

double serie_ln_div(float x, int n) {
    double suma = 0.0;
    for (int i = 1; i <= n; i++) {
        double armonico = 0.0;
        for (int j = 1; j <= i; j++) armonico += 1.0 / j;
        
        double px = 1.0;
        for (int j = 0; j < i; j++) px *= x;
        
        double signo = (i % 2 == 0) ? -1.0 : 1.0;
        suma += signo * armonico * px;
    }
    return suma;
}

int main() {
    float x; int n;
    do {
        printf("Ingrese x (|x| < 1): ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_ln_div(x, n));
    return 0;
}