#include <stdio.h>

double bernoulli(int k) {
    double B[50];
    B[0] = 1.0;

    for (int m = 1; m <= k; m++) {
        double suma = 0.0;
        for (int i = 0; i < m; i++) {
            double comb = 1.0;
            // Calculo incremental
            for (int j = 1; j <= i; j++) {
                comb = comb * (m - j + 1) / j;
            }
            suma += comb * (B[i] / (m + 1.0 - i));
        }
        B[m] = -suma;
    }
    return B[k];
}

int main() {
    int k;
    do {
        printf("Ingrese k (0-40): ");
        scanf("%d", &k);
    } while (k < 0 || k > 40);

    printf("Resultado: %f\n", bernoulli(k));
    return 0;
}