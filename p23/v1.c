/*
 * Archivo: v1.c
 * Aproximacion de csc(x) con serie de Maclaurin.
 * Nivel 1: Calculo de componentes mediante ciclos independientes.
 *
 * Detalles:
 * En cada iteracion del bucle principal for, se calculan los Numeros de Bernoulli, 
 * las potencias de base constante, las potencias de x y el factorial del 
 * denominador empleando ciclos internos.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p, doble_i;
    double x, resultado_total, num_bernoulli, combinatoria, suma_interna;
    double v_elevado, dos_elevado, el_factorial, x_elevada;

    printf("ingresa n y x: ");
    scanf("%d %lf", &n, &x);

    /* el primer termino siempre es 1/x */
    resultado_total = 1.0 / x;

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0; 

            for (v = 0; v <= k; v++) {
                
                /* Ciclo interno con while para v^(2i) */
                v_elevado = 1.0;
                p = 0;
                while (p < doble_i) {
                    v_elevado *= v;
                    p++;
                }

                suma_interna += (1 - 2 * (v % 2)) * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* ciclo con while para calcular 2^(2i-1) */
        dos_elevado = 1.0;
        j = 0;
        while (j < (doble_i - 1)) {
            dos_elevado *= 2.0;
            j++;
        }

        /* ciclo con while para el factorial (2i)! */
        el_factorial = 1.0;
        j = 1;
        while (j <= doble_i) {
            el_factorial *= j;
            j++;
        }

        /* ciclo con while para x^(2i-1) */
        x_elevada = 1.0;
        j = 0;
        while (j < (doble_i - 1)) {
            x_elevada *= x;
            j++;
        }

        /* Acumulacion directa */
        resultado_total += (2.0 * (dos_elevado - 1.0) * ((i % 2 == 0) ? -num_bernoulli : num_bernoulli) / el_factorial) * x_elevada;
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}