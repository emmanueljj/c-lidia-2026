/**
 * @file Ejercicio16.c
 * @brief Calculo de los Numeros de Bernoulli (Bk).
 */

#include <stdio.h>

/**
 * @brief Calcula el k-esimo numero de Bernoulli de forma recursiva/iterativa.
 * @param k Indice del numero deseado.
 * @return Valor de Bk como double.
 */

double calcular_serie(int k) {
    double B[50];
    int m, i;
    B[0] = 1.0;

    m = 1;
    while (m <= k) {
        double suma = 0.0;
        double comb = 1.0; // nCr para i=0 siempre es 1
        
        for (i = 0; i < m; i++) {
            suma += comb * (B[i] / (m + 1.0 - i));
            // Actualiza combinatoria para el siguiente i: nC(i+1)
            comb = comb * (m - i) / (i + 1);
        }
        B[m] = -suma;
        m++;
    }
    return B[k];
}

int main() {
    int k;
    do {
        printf("Ingrese k: ");
        scanf("%d", &k);
    } while (k < 0 || k >= 50);

    printf("Resultado: %f\n", calcular_serie(k));
    return 0;
}