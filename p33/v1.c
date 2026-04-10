/*
 * Archivo: v1.c
 * Aproximacion de e^(sen(x)) con serie de Maclaurin.
 * Nivel 1: Calculo de componentes mediante ciclos independientes.
 *
 * Detalles:
 * Se divide el calculo en dos etapas. Primero se evalua u = sen(x) 
 * y posteriormente se evalua e^u. En cada iteracion de los bucles 
 * principales for, se emplean ciclos while internos para calcular 
 * potencias y factoriales.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, u = 0.0, sumatoria = 1.0, numerador, denominador, signo;

    printf("Ingrese n y x: ");
    scanf("%d %lf", &n, &x);

    /* Bucle principal para calcular u = sen(x) (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        exponente = 2 * i - 1;

        /* calcula potencias de x con while */
        numerador = 1.0;
        j = 0;
        while (j < exponente) {
            numerador *= x;
            j++;
        }

        /* calcula factoriales con while */
        denominador = 1.0;
        j = 1;
        while (j <= exponente) {
            denominador *= j;
            j++;
        }

        /* determina el signo alterno */
        signo = (i % 2 == 0) ? -1.0 : 1.0;

        u += signo * (numerador / denominador);
    }

    /* Bucle principal para calcular e^u (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        
        /* calcula potencias de u con while */
        numerador = 1.0;
        j = 0;
        while (j < i) {
            numerador *= u;
            j++;
        }

        /* calcula factoriales con while */
        denominador = 1.0;
        j = 1;
        while (j <= i) {
            denominador *= j;
            j++;
        }

        /* ensambla el termino de e^u */
        sumatoria += numerador / denominador;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}