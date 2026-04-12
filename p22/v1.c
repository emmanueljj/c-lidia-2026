#include <stdio.h>

int main() {
    int n, i, j, m, p;
    float x;
    double suma_sec = 0.0, euler, powx, fact, suma_m;

    printf("Ingrese x: "); scanf("%f", &x);
    printf("Ingrese n: "); scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // --- CALCULO DE EULER E2i (Logica del Ejercicio 18) ---
        suma_m = 0.0;
        int limite_m = 2 * i + 1;
        for (m = 1; m <= limite_m; m += 2) {
            double suma_j = 0.0;
            for (j = 0; j <= m; j++) {
                double c = 1.0, pb = 1.0;
                for (p = 1; p <= j; p++) c = c * (m - p + 1) / p;
                for (p = 0; p < limite_m; p++) pb *= (m - 2.0 * j);
                suma_j += ((j % 2 == 0) ? 1.0 : -1.0) * c * pb;
            }
            double p2 = 1.0;
            for (p = 0; p < m; p++) p2 *= 2.0;
            double si = ((m - 1) / 2 % 2 == 0) ? 1.0 : -1.0;
            suma_m += si * (suma_j / (p2 * m));
        }
        euler = suma_m;

        // --- CALCULO DE POTENCIA Y FACTORIAL ---
        powx = 1.0;
        for (j = 0; j < (2 * i); j++) powx *= x;
        fact = 1.0;
        for (j = 1; j <= (2 * i); j++) fact *= j;

        double signo_n = (i % 2 == 0) ? 1.0 : -1.0;
        suma_sec += (signo_n * euler * powx) / fact;
    }

    printf("Resultado: %f\n", suma_sec);
    return 0;
}