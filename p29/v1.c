#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p, doble_i;
    double x, sumatoria = 0.0, num_bernoulli, suma_interna, combinatoria, v_elevado, cuatro_elevado, el_factorial, x_elevada;

    scanf("%d %lf", &n, &x);

    /*bucle principal para cada termino*/
    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        /*calcula numero de bernoulli*/
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                for (p = 0; p < doble_i; p++) {
                    v_elevado *= v;
                }
                suma_interna += ((v % 2 == 0) ? 1.0 : -1.0) * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /*calcula potencias de 4*/
        cuatro_elevado = 1.0;
        for (j = 0; j < i; j++) {
            cuatro_elevado *= 4.0;
        }

        /*calcula factoriales*/
        el_factorial = 1.0;
        for (j = 1; j <= doble_i; j++) {
            el_factorial *= j;
        }

        /*calcula potencias de x*/
        x_elevada = 1.0;
        for (j = 0; j < (doble_i - 1); j++) {
            x_elevada *= x;
        }

        /*ensambla el termino y acumula*/
        sumatoria += (num_bernoulli * cuatro_elevado * (cuatro_elevado - 1.0) / el_factorial) * x_elevada;
    }

    printf("%lf\n", sumatoria);
    return 0;
}