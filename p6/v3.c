/**
 * @file Ejercicio6.c
 * @brief Calculo de la serie 1/(i*(i+2)) que converge a 3/4.
 * @author Alejandro Leon Lopez
 * @date 2026
 */

#include <stdio.h>

/**
 * @brief Calcula la aproximacion de la serie de forma lineal.
 * @param n Numero de terminos a sumar.
 * @return Suma acumulada de la serie.
 * @par Complejidad
 * Tiempo: O(n).
 */
double calcular_serie(int n) {
    double suma = 0.0;
    int i = 1;

    // Se utiliza while para el proceso incremental
    while (i <= n) {
        suma += 1.0 / (i * (i + 2.0));
        i++;
    }
    return suma;
}

int main() {
    int n;

    // Validacion de entrada
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(n));

    return 0;
}