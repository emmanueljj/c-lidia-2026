/*
 * Archivo: v2.c
 * Aproximacion de csc(x) con serie de Maclaurin.
 * Nivel 2: Incluye validacion de dominio y estructura for principal.
 *
 * Detalles:
 * Se restringe la entrada de iteraciones y se asegura que x se mantenga 
 * dentro del dominio de convergencia. El bucle principal utiliza for, 
 * mientras que los calculos de potencias y factoriales se realizan con while.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p;
    double x, resultado_total, num_bernoulli, suma_interna, combinatoria;
    double signo_v, v_elevado, dos_elevado, el_factorial, x_elevada;
    
    /* Validacion y prevencion de division por cero */
    do {
        printf("Ingresa n (>=1) y x (0 < |x| < 3.14159): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || x <= -3.14159 || x >= 3.14159 || x == 0.0);

    resultado_total = 1.0 / x;

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        num_bernoulli = 0.0;

        for (k = 0; k <= (2 * i); k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0; 

            for (v = 0; v <= k; v++) {
                
                /* Ciclo interno con while */
                v_elevado = 1.0;
                p = 0;
                while (p < (2 * i)) {
                    v_elevado *= v;
                    p++;
                }

                suma_interna += signo_v * combinatoria * v_elevado;
                combinatoria = combinatoria * (k - v) / (v + 1.0);                
                signo_v *= -1.0; 
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        dos_elevado = 1.0;
        x_elevada = 1.0;
        
        /* Ciclo combinado con while para potencias */
        j = 0;
        while (j < 2 * i - 1) {
            dos_elevado *= 2.0;
            x_elevada *= x;
            j++;
        }

        /* Ciclo con while para el factorial */
        el_factorial = 1.0;
        j = 1;
        while (j <= 2 * i) {
            el_factorial *= j;
            j++;
        }

        resultado_total += (2.0 * (dos_elevado - 1.0) * ((i % 2 == 0) ? -num_bernoulli : num_bernoulli) / el_factorial) * x_elevada;
    }

    printf("\nresultado %lf\n", resultado_total);
    return 0;
}