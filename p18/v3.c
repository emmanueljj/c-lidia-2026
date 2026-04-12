/**
 * @file Ejercicio18.c
 * @brief Calculo de los numeros de Euler E2k mediante sumatoria doble.
 */

#include <stdio.h>

/**
 * @brief Calcula el numero de Euler E2k.
 * @param k Indice del numero de Euler (E0, E2, E4...).
 * @return Valor de E2k como double.
 */

double calcular_serie(int k) {
    double suma_total = 0.0;
    int n = 2 * k + 1;
    int m = 1;

    while (m <= n) {
        double suma_interna = 0.0;
        double comb = 1.0;
        
        for (int j = 0; j <= m; j++) {
            double base = (double)m - 2.0 * j;
            double p_base = 1.0;
            for (int p = 0; p < n; p++) p_base *= base;

            double sj = (j % 2 == 0) ? 1.0 : -1.0;
            suma_interna += sj * comb * p_base;
            
            comb = comb * (m - j) / (j + 1);
        }

        double p2 = 1.0;
        for (int p = 0; p < m; p++) p2 *= 2.0;

        // El termino i/i^m es real solo si m es impar
        double si = ((m - 1) / 2 % 2 == 0) ? 1.0 : -1.0;
        suma_total += si * (suma_interna / (p2 * m));
        
        m += 2; // Brincamos de 2 en 2 para solo evaluar m impares
    }
    return suma_total;
}

int main() {
    int k;
    do {
        printf("Ingrese k: ");
        scanf("%d", &k);
    } while (k < 0);

    printf("Resultado: %f\n", calcular_serie(k));

    return 0;
}