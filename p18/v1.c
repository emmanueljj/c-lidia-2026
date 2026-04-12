#include <stdio.h>

int main() {
    int k, m, j, p;
    double suma_m = 0.0, suma_j, comb, pow_base, pow2;
    int n;

    printf("Ingrese k: ");
    scanf("%d", &k);
    n = 2 * k + 1;

    for (m = 1; m <= n; m++) {
        // Solo los m impares aportan a la parte real del numero de Euler
        if (m % 2 != 0) {
            suma_j = 0.0;
            for (j = 0; j <= m; j++) {
                // Calcular combinacion mCj
                double f1 = 1.0, f2 = 1.0, f3 = 1.0;
                for (p = 1; p <= m; p++) f1 *= p;
                for (p = 1; p <= j; p++) f2 *= p;
                for (p = 1; p <= (m - j); p++) f3 *= p;
                comb = f1 / (f2 * f3);

                // Calcular (m-2j)^n
                pow_base = 1.0;
                for (p = 0; p < n; p++) pow_base *= (m - 2.0 * j);

                double signo_j = (j % 2 == 0) ? 1.0 : -1.0;
                suma_j += signo_j * comb * pow_base;
            }

            // Potencia de 2^m
            pow2 = 1.0;
            for (p = 0; p < m; p++) pow2 *= 2.0;

            // Determinar signo segun la potencia de i (i / i^m)
            double signo_i = ((m - 1) / 2 % 2 == 0) ? 1.0 : -1.0;
            suma_m += signo_i * (suma_j / (pow2 * m));
        }
    }

    printf("Resultado: %f\n", suma_m);
    return 0;
}