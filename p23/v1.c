#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p, doble_i;
    double x, resultado_total, num_bernoulli, combinatoria, suma_interna, v_elevado, dos_elevado, el_factorial, x_elevada;

    printf("ingresa n y x: ");
    scanf("%d %lf", &n, &x);

    /* el primer termino siempre es 1/x */
    resultado_total = 1.0 / x;

    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0; 

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                for (p = 0; p < doble_i; p++) v_elevado *= v;

                suma_interna += (1-2*(v%2)) * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* ciclo para calcular 2^(2i-1) */
        dos_elevado = 1.0;
        for (j = 0; j < (doble_i - 1); j++) dos_elevado *= 2.0;

        /* para el factorial (2i)! */
        el_factorial = 1.0;
        for (j = 1; j <= doble_i; j++) el_factorial *= j;

        /* para x^(2i-1) */
        x_elevada = 1.0;
        for (j = 0; j < (doble_i - 1); j++) x_elevada *= x;

        /* Acumulacion directa, el ternario extrae el valor absoluto de bernoulli */
        resultado_total += (2.0 * (dos_elevado - 1.0) * ((i % 2 == 0) ? -num_bernoulli : num_bernoulli) / el_factorial) * x_elevada;
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}