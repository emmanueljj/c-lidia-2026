#include <stdio.h>

double obtener_euler(int k) {
    double suma_total = 0.0;
    int n = 2 * k + 1;
    for (int m = 1; m <= n; m += 2) {
        double suma_j = 0.0;
        for (int j = 0; j <= m; j++) {
            double c = 1.0;
            for (int p = 1; p <= j; p++) c = c * (m - p + 1) / p;
            double pb = 1.0;
            for (int p = 0; p < n; p++) pb *= (m - 2.0 * j);
            suma_j += ((j % 2 == 0) ? 1.0 : -1.0) * c * pb;
        }
        double p2 = 1.0;
        for (int p = 0; p < m; p++) p2 *= 2.0;
        double si = ((m - 1) / 2 % 2 == 0) ? 1.0 : -1.0;
        suma_total += si * (suma_j / (p2 * m));
    }
    return suma_total;
}

double serie_sec(float x, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double px = 1.0, f = 1.0;
        for (int j = 1; j <= (2 * i); j++) {
            px *= x;
            f *= j;
        }
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += (signo * obtener_euler(i) * px) / f;
    }
    return suma;
}

int main() {
    float x; int n;
    do {
        printf("Ingrese x (|x| < 1.5708): ");
        scanf("%f", &x);
    } while (x <= -1.5708 || x >= 1.5708);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_sec(x, n));
    return 0;
}