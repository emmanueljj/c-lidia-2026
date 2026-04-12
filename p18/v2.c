#include <stdio.h>

double euler_2k(int k) {
    double suma_m = 0.0;
    int n = 2 * k + 1;

    for (int m = 1; m <= n; m += 2) {
        double suma_j = 0.0;
        for (int j = 0; j <= m; j++) {
            double comb = 1.0;
            for (int p = 1; p <= j; p++) comb = comb * (m - p + 1) / p;

            double pow_base = 1.0;
            for (int p = 0; p < n; p++) pow_base *= (m - 2.0 * j);

            double signo_j = (j % 2 == 0) ? 1.0 : -1.0;
            suma_j += signo_j * comb * pow_base;
        }

        double pow2 = 1.0;
        for (int p = 0; p < m; p++) pow2 *= 2.0;

        double signo_i = ((m - 1) / 2 % 2 == 0) ? 1.0 : -1.0;
        suma_m += signo_i * (suma_j / (pow2 * m));
    }
    return suma_m;
}

int main() {
    int k;
    do {
        printf("Ingrese k (0-10): ");
        scanf("%d", &k);
    } while (k < 0 || k > 10);

    printf("Resultado: %f\n", euler_2k(k));
    return 0;
}