/**
 * @file Ejercicio4.c
 * @brief Calculo de la serie PI^2/8 usando inversos de cuadrados impares.
 */

#include <stdio.h>

/**
 * @brief Sumatoria de los primeros n terminos de la serie.
 * @param n Cantidad de terminos.
 * @return Resultado acumulado.
 * @par Complejidad
 * Tiempo: O(n).
 */
double calcular_serie(int n) {
    double suma = 0.0;
    double impar;
    int i = 0;

    while (i < n) {
        impar = 2.0 * i + 1.0;
        suma += 1.0 / (impar * impar);
        i++;
    }
    return suma;
}

int main() {
    int n;

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(n));

    return 0;
}