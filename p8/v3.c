/**
 * @file Ejercicio8.c
 * @brief Calculo de la serie xe^x mediante recurrencia.
 */

#include <stdio.h>

/**
 * @brief Calcula la serie de forma lineal O(n).
 * @param x Valor de la variable.
 * @param n Numero de terminos.
 * @return Suma acumulada de la serie.
 * @par Complejidad
 * Tiempo: O(n).
 */

double calcular_serie(float x, int n) {
    double suma = x;
    double termino = x;
    int i = 1;

    while (i < n) {
        termino *= (x / i);
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