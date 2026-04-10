/*
 * Archivo: v2.c
 * Aproximacion de tanh(x) con serie de Maclaurin.
 * Nivel 2: Inclusion de validacion de dominio y estabilizacion de la solucion.
 *
 * Detalles:
 * Se restringe la entrada de iteraciones y el dominio de convergencia (|x| < Pi/2).
 * Se integra un criterio de paro (epsilon) para la estabilizacion numerica. 
 * El bucle principal utiliza for, mientras que las potencias y factoriales 
 * se evaluan con ciclos while.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j, k, v, p, doble_i;
    double x, sumatoria = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v;
    double v_elevado, cuatro_elevado, el_factorial, x_elevada, termino;
    double epsilon = 1e-8;

    /* Validacion de dominio (|x| < Pi/2) */
    do {
        printf("Ingrese n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.570796327);

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                
                /* Ciclo interno con while */
                p = 0;
                while (p < doble_i) {
                    v_elevado *= v;
                    p++;
                }

                suma_interna += signo_v * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
                signo_v *= -1.0;
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* Ciclo con while para 4^i */
        cuatro_elevado = 1.0;
        j = 0;
        while (j < i) {
            cuatro_elevado *= 4.0;
            j++;
        }

        /* Ciclo con while para (2i)! */
        el_factorial = 1.0;
        j = 1;
        while (j <= doble_i) {
            el_factorial *= j;
            j++;
        }

        /* Ciclo con while para x^(2i-1) */
        x_elevada = 1.0;
        j = 0;
        while (j < (doble_i - 1)) {
            x_elevada *= x;
            j++;
        }

        /* Ensamblaje del termino iterativo */
        termino = (num_bernoulli * cuatro_elevado * (cuatro_elevado - 1.0) / el_factorial) * x_elevada;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        sumatoria += termino;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}