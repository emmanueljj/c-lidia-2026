#include <stdio.h>

int main() {
    int k, i, j, m;
    double B[50], suma, comb, f1, f2, f3;

    printf("Ingrese k: ");
    scanf("%d", &k);

    B[0] = 1.0; // Caso base 

    for (m = 1; m <= k; m++) {
        suma = 0.0;
        for (i = 0; i < m; i++) {
            // Calcula nCr = m! / (i! * (m-i)!) desde cero
            for (j = 1, f1 = 1.0; j <= m; j++) f1 *= j;
            for (j = 1, f2 = 1.0; j <= i; j++) f2 *= j;
            for (j = 1, f3 = 1.0; j <= (m - i); j++) f3 *= j;
            
            comb = f1 / (f2 * f3);
            suma += comb * (B[i] / (m + 1.0 - i));
        }
        B[m] = -suma;
    }

    printf("Resultado: %f\n", B[k]);
    return 0;
}