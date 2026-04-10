/*
 * Archivo: v2.c
 * Aproximacion de tan(x) con serie de Maclaurin.
 * Nivel 2: Incluye validacion de dominio, estabilizacion numerica (Epsilon)
 * y estructura for principal.
 *
 * Detalles:
 * Se restringe la entrada de iteraciones y se asegura que x se mantenga 
 * dentro del dominio de convergencia. El bucle principal utiliza for, 
 * mientras que los calculos de potencias y factoriales se realizan con while.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j, k, v, p, doble_i;
    double x, resultado_total = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado;
    double factorial, x_elevada, cuatro_elevado, termino;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do {
        printf("Ingresa n (>=1) y x (|x| < 1.570796): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.570796);

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
                
                /* Alternancia de signo por multiplicacion */
                signo_v *= -1.0; 
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* Calcular 4^i con while */
        cuatro_elevado = 1.0;
        j = 0;
        while (j < i) {
            cuatro_elevado *= 4.0;
            j++;
        }

        /* Calcular (2i)! con while */
        factorial = 1.0;
        j = 1;
        while (j <= doble_i) {
            factorial *= j;
            j++;
        }

        /* Calcular x^(2i-1) con while */
        x_elevada = 1.0;
        j = 0;
        while (j < (doble_i - 1)) {
            x_elevada *= x;
            j++;
        }

        /* Ensamblaje del termino */
        termino = (num_bernoulli * ((i % 2 != 0) ? -cuatro_elevado : cuatro_elevado) * (1.0 - cuatro_elevado) / factorial) * x_elevada;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        /* Acumulacion directa */
        resultado_total += termino;
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}