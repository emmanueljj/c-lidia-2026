#include <stdio.h>

int main(void) {

    int n, i, k, v, doble_i, exp;
    double x, resultado_total, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, base_v;
    double dos_elevado = 2.0, el_factorial = 1.0, x_elevada;

    do {
        printf("ingresa n (1 a 12) y x (0 < |x| < 3.14159): \n");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || n > 12 || x <= -3.14159 || x >= 3.14159 || x == 0.0);

    resultado_total = 1.0 / x;
    x_elevada = x; /* Para i=1, x^(2(1)-1) es x^1 */

    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        /* NUCLEO DE BERNOULLI (mismo que p23) */
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                base_v = v;
                exp = doble_i;
                
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

        /* actualizamos el factorial multiplicando por los siguientes dos numeros */
        el_factorial *= doble_i * (doble_i - 1.0); 

        /* ensamblaje mejor calculo de signo de Bernoulli */
        resultado_total += (2.0 * (dos_elevado - 1.0) * ((-1+2*(i%2))*num_bernoulli) / el_factorial) * x_elevada;

        /* preparamos variables para la siguiente vuelta: x^1 pasa a x^3, 2^1 pasa a 2^3 */
        x_elevada *= (x * x); 
        dos_elevado *= 4.0;
    }

    printf("resultado : %lf\n", resultado_total);
    return 0;
}