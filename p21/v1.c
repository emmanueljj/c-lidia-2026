/*
 * Archivo: v1.c
 * Aproximacion de tan(x) con serie de Maclaurin.
 * Nivel 1: Calculo de componentes mediante ciclos independientes.
 *
 * Detalles:
 * En cada iteracion del bucle principal, se calculan los Numeros de Bernoulli, 
 * las potencias de base constante, las potencias de x y el factorial del 
 * denominador desde cero, empleando ciclos internos separados.
 */
#include <stdio.h>

int main(void) {
    int n, i, j, k, v, p, doble_i, signo;
    double x, resultado_total = 0.0, num_bernoulli, combinatoria, suma_interna;
    double v_elevado, menos4_elevado, cuatro_elevado, factorial, x_elevada, termino_listo;

    printf("Ingresa n y x: ");
    scanf("%d %lf", &n, &x);

    /* Bucle principal: calcula cada termino de tan(x) */
    for (i = 1; i <= n; i++) {
        
        doble_i = 2 * i; 
        num_bernoulli = 0.0;

        /* Calcular el Numero de Bernoulli (B_2i) */
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0; 

            for (v = 0; v <= k; v++) {
                signo = (v % 2 == 0) ? 1 : -1;

                /* Ciclo iterativo para v^(2i) */
                v_elevado = 1.0;
                p = 0;
                while (p < doble_i) {
                    v_elevado *= v;
                    p++;
                }

                suma_interna += signo * combinatoria * v_elevado;

                /* Calcular la combinatoria */
                combinatoria = combinatoria * (k - v) / (v + 1.0);
            }
            num_bernoulli += suma_interna / (k + 1.0);
        }

        /* Calcular la potencia de (-4) con ciclo while */
        menos4_elevado = 1.0;
        j = 0;
        while (j < i) {
            menos4_elevado *= -4.0;
            j++;
        }

        /* Calcular la potencia de 4 con ciclo while */
        cuatro_elevado = 1.0;
        j = 0;
        while (j < i) {
            cuatro_elevado *= 4.0;
            j++;
        }

        /* Calcular el factorial del denominador con ciclo while */
        factorial = 1.0;
        j = 1;
        while (j <= doble_i) {
            factorial *= j;
            j++;
        }

        /* Calcular x elevada a la (2i - 1) con ciclo while */
        x_elevada = 1.0;
        j = 0;
        while (j < (doble_i - 1)) {
            x_elevada *= x;
            j++;
        }

        /* Ensamble del termino y acumulacion */
        termino_listo = (num_bernoulli * menos4_elevado * (1.0 - cuatro_elevado) / factorial) * x_elevada;
        resultado_total += termino_listo;
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}