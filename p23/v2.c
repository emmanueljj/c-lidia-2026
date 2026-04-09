#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p;
    double x, resultado_total, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, dos_elevado, el_factorial, x_elevada;
    
    /*  validacion y prevencion de division por cero. */
    do {
        printf("Ingresa n (>=1) y x (0 < |x| < 3.14159): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || x <= -3.14159 || x >= 3.14159 || x == 0.0);

    resultado_total = 1.0 / x;

    for (i = 1; i <= n; i++) {
        num_bernoulli = 0.0;

        for (k = 0; k <= (2*i); k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0; 

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                for (p = 0; p < (2*i); p++) v_elevado *= v;

                suma_interna += signo_v * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);                
                signo_v *= -1.0; 
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        dos_elevado = 1.0;
        x_elevada = 1.0;
        for (j = 0; j < 2*i - 1; j++){
            dos_elevado *= 2.0;
            x_elevada *= x;
        }

        el_factorial = 1.0;
        for (j = 1; j <= 2*i; j++) el_factorial *= j;

        resultado_total += (2.0 * (dos_elevado - 1.0) * ((i % 2 == 0) ? -num_bernoulli : num_bernoulli) / el_factorial) * x_elevada;
    }

    printf("\nresultado %lf\n", resultado_total);
    return 0;
}