#include <stdio.h>
#include <math.h>

int main(void) {
    /* variables*/
    int n, i, j, k, v, p, doble_i;
    double x, resultado_total = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado;
    double factorial, x_elevada, cuatro_elevado;

    /*se implemento la valdiacion de domnio*/
    do {
        printf("Ingresa n (>=1) y x (|x| < 1.570796): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.570796);


    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0; 

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                
                for (p = 0; p < doble_i; p++) v_elevado *= v;

                suma_interna += signo_v * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);
                
                /*multiplicando por -1 se logra alternar*/
                signo_v *= -1.0; 
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* Solo calculamos 4^i */
        cuatro_elevado = 1.0;
        for (j = 0; j < i; j++) cuatro_elevado *= 4.0;

        factorial = 1.0;
        for (j = 1; j <= doble_i; j++) factorial *= j;

        x_elevada = 1.0;
        for (j = 0; j < (doble_i - 1); j++) x_elevada *= x;

        /* Ensamblaje eliminado, variables de un solo uso eliminadas. 
         * Se acumula directo y se deduce (-4)^i usando operador ternario: 
         * Si 'i' es impar, es negativo. Si es par, es positivo. */
        resultado_total += (num_bernoulli * ((i % 2 != 0) ? -cuatro_elevado : cuatro_elevado) * (1.0 - cuatro_elevado) / factorial) * x_elevada;
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}