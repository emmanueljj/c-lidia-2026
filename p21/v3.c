#include <stdio.h>
#include <math.h>

int main(void) {
    /* 1. Declaracion exclusiva en bloque superior. Minimas variables posibles. */
    int n, i, k, v, doble_i, exp;
    double x, resultado_total = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, base_v;
    double cuatro_elevado = 1.0, el_factorial = 1.0, x_elevada;

    do {
        printf("Ingresa n (1 a 12) y x (|x| < 1.570796): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || n > 12 || fabs(x) >= 1.570796);

    x_elevada = x; 

    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        /* NUCLEO DE BERNOULLI: O(n^3)*/
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                base_v = v;
                exp = doble_i;
                
                /* Exponenciacion Binaria : Destruye el ciclo 'for' para calcular v^(2i) */
                while (exp > 0) {
                    /* 3. Sin llaves para una linea */
                    if (exp % 2 != 0) v_elevado *= base_v; 
                    base_v *= base_v;
                    exp /= 2;
                }

                suma_interna += signo_v * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
                signo_v *= -1.0;    
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* Ya no recalculamos nada (q no sean terminos de bernoulli) desde cero.*/
        cuatro_elevado *= 4.0;
        el_factorial *= doble_i * (doble_i - 1.0); /* Actualiza el factorial saltando 2 pasos */

        resultado_total += (num_bernoulli * ((i % 2 != 0) ? -cuatro_elevado : cuatro_elevado) * (1.0 - cuatro_elevado) / el_factorial) * x_elevada;
        /* Prepara x para la siguiente vuelta (de x^1 a x^3, a x^5...) */
        x_elevada *= (x * x); 
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}