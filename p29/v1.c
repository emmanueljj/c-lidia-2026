/*
 * Archivo: v1.c
 * Aproximacion de tanh(x) con serie de Maclaurin.
 * Nivel 1: Calculo de componentes mediante ciclos independientes.
 *
 * Detalles:
 * En cada iteracion del bucle principal for, se calculan los Numeros de Bernoulli, 
 * las potencias de base constante, las potencias de x y el factorial del 
 * denominador empleando ciclos internos while independientes.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p, doble_i;
    double x, sumatoria = 0.0, num_bernoulli, suma_interna, combinatoria, v_elevado, cuatro_elevado, el_factorial, x_elevada;

    printf("Ingrese n y x: ");
    scanf("%d %lf", &n, &x);

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        /* Calcula numero de Bernoulli */
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                
                /* Ciclo interno con while para la potencia */
                p = 0;
                while (p < doble_i) {
                    v_elevado *= v;
                    p++;
                }
                
                suma_interna += ((v % 2 == 0) ? 1.0 : -1.0) * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* Calcula potencias de 4 con while */
        cuatro_elevado = 1.0;
        j = 0;
        while (j < i) {
            cuatro_elevado *= 4.0;
            j++;
        }

        /* Calcula factoriales con while */
        el_factorial = 1.0;
        j = 1;
        while (j <= doble_i) {
            el_factorial *= j;
            j++;
        }

        /* Calcula potencias de x con while */
        x_elevada = 1.0;
        j = 0;
        while (j < (doble_i - 1)) {
            x_elevada *= x;
            j++;
        }

        /* Ensambla el termino y acumula */
        sumatoria += (num_bernoulli * cuatro_elevado * (cuatro_elevado - 1.0) / el_factorial) * x_elevada;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}