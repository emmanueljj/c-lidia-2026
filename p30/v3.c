/**
 * @file Ejercicio30.c
 * @brief Calculo de arcsenh(x) mediante serie de potencias optimizada.
 */

#include <stdio.h>

/**
 * @brief Aproxima arcsenh(x) con complejidad lineal O(n).
 * @param x Valor de la variable (|x| < 1).
 * @param n Numero de terminos.
 * @return Suma de la serie.
 */

double calcular_serie(float x, int n) {
    double suma = x;
    double termino = x;
    int i = 0;

    // Relacion de recurrencia para evitar ciclos anidados
    while (i < n - 1) {
        termino *= -(x * x * (2.0 * i + 1.0) * (2.0 * i + 1.0)) / ((2.0 * i + 2.0) * (2.0 * i + 3.0));
        suma += termino;
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
    } while (x <= -1.0 || x >= 1.0);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, n));

    return 0;
}