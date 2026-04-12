/**
 * @file Ejercicio14.c
 * @brief Calculo de la serie binomial (1+x)^alpha.
 */

#include <stdio.h>

/**
 * @brief Calcula la serie de forma lineal O(n).
 * @param x Valor de la base.
 * @param alpha Exponente.
 * @param n Numero de terminos.
 * @return Suma de la serie.
 */

double calcular_serie(float x, float alpha, int n) {
    double suma = 1.0;    // El primer termino (i=0) siempre es 1
    double termino = 1.0;
    int i = 0;

    while (i < n - 1) {
        // Relacion de recurrencia: T_{i+1} = T_i * x * (alpha - i) / (i + 1)
        termino *= (x * (alpha - i) / (i + 1));
        suma += termino;
        i++;
    }
    return suma;
}

int main() {
    float x, alpha;
    int n;

    do {
        printf("Ingrese x: ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);

    printf("Ingrese alpha: ");
    scanf("%f", &alpha);

    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, alpha, n));

    return 0;
}