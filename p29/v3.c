#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, k, v, doble_i, exp;
    double x, sumatoria = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, base_v;
    double cuatro_elevado = 4.0, el_factorial = 1.0, x_elevada;

    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1 || n > 12 || fabs(x) >= 1.570796327);

    /* inicializacion de x_elevada para la recurrencia O(1) */
    x_elevada = x;

    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                base_v = v;
                exp = doble_i;
                
                /* Exponenciacion Binaria */
                while (exp > 0) {
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

        /* recurrencia para el factorial sin ciclos for */
        el_factorial *= doble_i * (doble_i - 1.0);

        sumatoria += (num_bernoulli * cuatro_elevado * (cuatro_elevado - 1.0) / el_factorial) * x_elevada;

        /* actualizacion de las potencias para la siguiente iteracion */
        cuatro_elevado *= 4.0;
        x_elevada *= (x * x);
    }

    printf("%lf\n", sumatoria);
    return 0;
}