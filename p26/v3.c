/**
 * @file Ejercicio26.c
 * @brief Calculo de arcotangente para cualquier valor de x.
 */

#include <stdio.h>

/**
 * @brief Calcula atan(x) de forma eficiente usando recurrencia.
 * @param x Valor real.
 * @param n Numero de terminos.
 * @return Aproximacion de la arcotangente.
 */

double calcular_serie(float x, int n) {
    double suma = 0.0;
    int i = 0;

    if (x > -1.0 && x < 1.0) {
        double t = x; // primer termino i=0
        double x2 = x * x;
        while (i < n) {
            suma += t / (2 * i + 1);
            t *= -x2;
            i++;
        }
    } else {
        double p_medios = 1.57079632679;
        double t = 1.0 / x;
        double x2_inv = 1.0 / (x * x);
        while (i < n) {
            suma += t / (2 * i + 1);
            t *= -x2_inv;
            i++;
        }
        suma = (x >= 1.0 ? p_medios : -p_medios) - suma;
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