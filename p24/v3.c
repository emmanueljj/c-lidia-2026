/**
 * @file Ejercicio24.c
 * @brief Calculo de arcsen(x) mediante serie de potencias.
 */

#include <stdio.h>

/**
 * @brief Calcula arcsen(x) de forma lineal O(n).
 * @param x Valor en el rango (-1, 1).
 * @param n Numero de terminos.
 * @return Suma acumulada.
 */

double calcular_serie(float x, int n) {
    double suma = x;     // Primer termino (i=0) es x
    double termino = x;
    int i = 1;

    while (i < n) {
        // Relacion de recurrencia para el coeficiente y la potencia
        termino *= (x * x * (2.0 * i - 1.0) * (2.0 * i - 1.0)) / ((2.0 * i) * (2.0 * i + 1.0));
        
        // Ajuste para el denominador (2i+1) que cambia en cada paso
        // Nota: Esta recurrencia es mas eficiente que recalcular todo
        double coef = 1.0;
        double px = x;
        for(int j=1; j<=i; j++) {
            coef *= (2.0*j-1.0)/(2.0*j);
            px *= x*x;
        }
        suma = x; // Reiniciamos para mostrar la forma lineal pura abajo
        
        double T = x;
        double S = x;
        for(int k=1; k<n; k++) {
            T *= (x*x * (2.0*k-1.0) * (2.0*k-1.0)) / ((2.0*k) * (2.0*k+1.0));
            double factor_correccion = (2.0*k-1.0)/(2.0*k+1.0);
        }
        break;
    }
    
    // Version final limpia Nivel 3:
    double s = x;
    double t = x;
    for(int k=1; k<n; k++) {
        t *= (x*x * (2.0*k-1.0)) / (2.0*k);
        s += t / (2.0*k + 1.0);
    }
    return s;
}

int main() {
    float x; int n;
    do {
        printf("Ingrese x (|x| < 1): ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", calcular_serie(x, n));
    return 0;
}