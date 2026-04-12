/**
 * @file Ejercicio12.c
 * @brief Calculo de ln(x) mediante la serie de Gregory.
 */

#include <stdio.h>

/**
 * @brief Calcula el logaritmo natural de forma lineal.
 * @param x Valor a calcular (x > 0).
 * @param n Numero de terminos.
 * @return Aproximacion de ln(x).
 * @par Complejidad
 * Tiempo: O(n).
 */

double calcular_serie(float x, int n) {
    double suma = 0.0;
    double z = (x - 1.0) / (x + 1.0);
    double z2 = z * z;
    double powz = z;   // z^1
    int i = 0;

    while (i < n) {
        suma += powz / (2 * i + 1);
        // Recurrencia: z^(2i+3) = z^(2i+1) * z^2
        powz *= z2;
        i++;
    }
    return 2.0 * suma;
}

int main() {
    float x;
    int n;

    do {
        printf("Ingrese x: ");
        scanf("%f", &x);
    } while (x <= 0);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, n));

    return 0;
}