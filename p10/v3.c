/**
 * @file Ejercicio10.c
 * @brief Calculo de ln(1+x) mediante serie de potencias.
 */

#include <stdio.h>

/**
 * @brief Calcula la serie de forma eficiente sin ciclos anidados.
 * @param x Valor en el rango (-1, 1].
 * @param n Cantidad de terminos.
 * @return Suma de la serie.
 * @par Complejidad
 * Tiempo: O(n).
 */

double calcular_serie(float x, int n) {
    double suma = 0.0;
    double px = 1.0;     // Acumulador de potencia
    double signo = 1.0;  // El primer termino (i=1) es positivo
    int i = 1;

    while (i <= n) {
        px *= x;         // Actualiza potencia: x^i
        suma += (signo * px) / i;
        signo = -signo;  // Cambia el signo para la siguiente vuelta
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
    } while (x <= -1.0 || x > 1.0);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, n));

    return 0;
}