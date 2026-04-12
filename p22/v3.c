/**
 * @file Ejercicio22.c
 * @brief Calculo de la secante mediante la serie de Euler.
 */

#include <stdio.h>

/**
 * @brief Obtiene el numero de Euler.
 */

double euler_2k(int k) {
    double st = 0.0;
    int n = 2 * k + 1;
    int m = 1;
    while (m <= n) {
        double sj = 0.0, c = 1.0;
        for (int j = 0; j <= m; j++) {
            double pb = 1.0;
            for (int p = 0; p < n; p++) pb *= (m - 2.0 * j);
            sj += ((j % 2 == 0) ? 1.0 : -1.0) * c * pb;
            c = c * (m - j) / (j + 1);
        }
        double p2 = 1.0;
        for (int p = 0; p < m; p++) p2 *= 2.0;
        double si = ((m - 1) / 2 % 2 == 0) ? 1.0 : -1.0;
        st += si * (sj / (p2 * m));
        m += 2;
    }
    return st;
}

/**
 * @brief Calcula sec(x).
 */

double calcular_serie(float x, int n) {
    double suma = 1.0; // Termino n=0 es 1
    double px_f = 1.0; // Acumulador para x^(2n)/(2n)!
    int i = 1;

    while (i < n) {
        // Recurrencia para x^(2i)/(2i)!
        px_f *= (x * x) / ((2.0 * i - 1.0) * (2.0 * i));
        
        double s = (i % 2 == 0) ? 1.0 : -1.0;
        suma += s * euler_2k(i) * px_f;
        i++;
    }
    return suma;
}

int main() {
    float x;
    int n;

    do {
        printf("Ingrese x: ");
        scanf("%f", &x);
    } while (x <= -1.5708 || x >= 1.5708);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, n));

    return 0;
}