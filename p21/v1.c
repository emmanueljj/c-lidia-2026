#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p, doble_i, signo;
    double x, resultado_total = 0.0, num_bernoulli,combinatoria, suma_interna;
    double v_elevado, menos4_elevado, cuatro_elevado, factorial, x_elevada, termino_listo;

    printf("Ingresa n y x: ");
    scanf("%d %lf", &n, &x);

    /* Bucle principal:  calcula cade termino de tan(x)*/
    for (i = 1; i <= n; i++) {
        
        doble_i = 2 * i; /* Para no calcular 2*i a cada rato */
         num_bernoulli = 0.0;

        /* 1. Calcular Bernoulli (B_2i)  */
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0; 

            for (v = 0; v <= k; v++) {
                signo = (v % 2 == 0) ? 1 : -1;

                /* Ciclo para  v^(2i) */
                v_elevado = 1.0;
                for (p = 0; p < doble_i; p++) {
                    v_elevado *= v;
                }

                suma_interna += signo * combinatoria * v_elevado;

                /*  calcular la combinatoria sin factoriales */
                combinatoria = combinatoria * (k - v) / (v + 1.0);
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* 2. Calcular la potencia de (-4)  */
        menos4_elevado = 1.0;
        for (j = 0; j < i; j++) {
            menos4_elevado *= -4.0;
        }

        /* 3. Calcular la potencia de 4  */
        cuatro_elevado = 1.0;
        for (j = 0; j < i; j++) {
            cuatro_elevado *= 4.0;
        }

        /* 4. Calcular el factorial del denominador */
        factorial = 1.0;
        for (j = 1; j <= doble_i; j++) {
            factorial *= j;
        }

        /* 5. Calcular la x elevada a la (2i - 1)  */
        x_elevada = 1.0;
        for (j = 0; j < (doble_i - 1); j++) {
            x_elevada *= x;
        }

        /*  6. Ensamble del Termino y Acumulacion */
        termino_listo = (num_bernoulli * menos4_elevado * (1.0 - cuatro_elevado) / factorial) * x_elevada;
        resultado_total += termino_listo;
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}