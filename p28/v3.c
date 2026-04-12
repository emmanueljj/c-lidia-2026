/**
 * @file Ejercicio28.c
 * @brief Calculo del coseno hiperbolico mediante serie de potencias.
 */

#include <stdio.h>

/**
 * @brief Calcula cosh(x) usando relacion de recurrencia.
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Suma de la serie.
 * @par Complejidad
 * Tiempo: O(n).
 */

double calcular_serie(float x, int n) {
    double suma = 1.0;
    double termino = 1.0;
    int i = 1;

    while (i < n) {
        // Relacion de recurrencia: T_i = T_{i-1} * (x^2 / ((2i-1)*(2i)))
        termino *= (x * x) / ((2.0 * i - 1.0) * (2.0 * i));
        suma += termino;
        i++;
    }
    return suma;
}

int main() {
    float x;
    int n;

    printf("Ingrese x: ");
    scanf("%f", &x);
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, n));

    return 0;
}