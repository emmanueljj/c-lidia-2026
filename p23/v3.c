/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \csc(x)$ con serie de Maclaurin ($\displaystyle \mathcal{O}(n^3)$).
 *
 * @details
 * Serie:
 * $\displaystyle \csc(x) = \frac{1}{x} + \frac{x}{6} + \frac{7x^3}{360} + \dots + \frac{2(2^{2n-1}-1)B_n}{(2n)!}x^{2n-1} + \dots$
 *
 * Implementacion:
 * Se implementa una actualizacion por recurrencia para las potencias de x, 
 * las potencias de 2 y el factorial. El calculo de exponentes internos 
 * utiliza exponenciacion binaria. Incluye estabilizacion numerica.
 *
 * @par Entrada
 * - Un entero $\displaystyle n$ en el rango $\displaystyle 1 \leq n \leq 12$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle 0 < |x| < \pi$.
 *
 * @par Salida
 * Imprime:
 * @code
 * resultado : valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n^3)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 *
 * @note
 * Se limita $\displaystyle n$ a 12 para evitar el desbordamiento de las variables
 * de tipo double debido al crecimiento del factorial en el denominador.
 */
#include <stdio.h>
#include <math.h>

int main(void) {

    int n, i, k, v, doble_i, exp;
    double epsilon = 1e-8;
    double x, resultado_total, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, base_v;
    double dos_elevado = 2.0, el_factorial = 1.0, x_elevada, termino;

    /* Validacion de dominio */
    do {
        printf("ingresa n (1 a 12) y x (0 < |x| < 3.14159): \n");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || n > 12 || x <= -3.14159 || x >= 3.14159 || x == 0.0);

    resultado_total = 1.0 / x;
    x_elevada = x; 

    /* Bucle principal (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        doble_i = 2 * i;
        num_bernoulli = 0.0;

        /* Calculo de Numeros de Bernoulli */
        for (k = 0; k <= doble_i; k++) {
            suma_interna = 0.0;
            combinatoria = 1.0;
            signo_v = 1.0;

            for (v = 0; v <= k; v++) {
                v_elevado = 1.0;
                base_v = v;
                exp = doble_i;
                
                /* Exponenciacion binaria iterativa con while */
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

        /* Actualizacion de variables por recurrencia */
        el_factorial *= doble_i * (doble_i - 1.0); 

        /* Ensamblaje del termino iterativo COMPLETO */
        termino = (2.0 * (dos_elevado - 1.0) * ((-1 + 2 * (i % 2)) * num_bernoulli) / el_factorial) * x_elevada;

        /* Criterio de paro numerico (Evaluando el termino final) */
        if (fabs(termino) < epsilon) {
            break;
        }

        /* Acumulacion al resultado final */
        resultado_total += termino;

        /* Preparacion de variables para la siguiente iteracion */
        x_elevada *= (x * x); 
        dos_elevado *= 4.0;
    }

    printf("resultado : %lf\n", resultado_total);
    return 0;
}