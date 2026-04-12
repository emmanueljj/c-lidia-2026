#include <stdio.h>

double serie_atan(float x, int n) {
    double suma = 0.0;
    if (x > -1.0 && x < 1.0) {
        for (int i = 0; i < n; i++) {
            double px = 1.0;
            for (int j = 0; j < (2 * i + 1); j++) px *= x;
            double signo = (i % 2 == 0) ? 1.0 : -1.0;
            suma += (signo * px) / (2 * i + 1);
        }
    } else {
        // Caso para |x| >= 1
        double p_medios = 1.57079632679;
        for (int i = 0; i < n; i++) {
            double den_x = 1.0;
            for (int j = 0; j < (2 * i + 1); j++) den_x *= x;
            double signo = (i % 2 == 0) ? 1.0 : -1.0;
            suma += (signo) / ((2 * i + 1) * den_x);
        }
        suma = (x >= 1.0 ? p_medios : -p_medios) - suma;
    }
    return suma;
}

int main() {
    float x; int n;
    printf("Ingrese x: "); scanf("%f", &x);
    do {
        printf("Ingrese n: "); scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_atan(x, n));
    return 0;
}