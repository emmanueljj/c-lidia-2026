/**
 * @file Ejercicio32.c
 * @brief Calculo de ln(1+x)/(1+x) usando numeros armonicos.
 */

#include <stdio.h>

/**
 * @brief Calcula la serie de forma lineal reutilizando valores previos.
 * @param x Valor de la variable (|x| < 1).
 * @param n Cantidad de terminos.
 * @return Resultado de la sumatoria.
 */

double calcular_serie(float x, int n) {
    double suma = 0.0;
    double px = 1.0;       // Acumulador de potencia
    double armonico = 0.0; // Acumulador de numero armonico
    double signo = 1.0;
    int i = 1;

    while (i <= n) {
        armonico += 1.0 / i; // H_i = H_{i-1} + 1/i
        px *= x;             // x^i = x^{i-1} * x
        
        suma += signo * armonico * px;
        
        signo = -signo;
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