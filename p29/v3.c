/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \tanh(x)$ con serie de Maclaurin ($\displaystyle \mathcal{O}(n^3)$).
 *
 * @details
 * Serie:
 * $\displaystyle \tanh(x) = x - \frac{1}{3}x^3 + \frac{2}{15}x^5 - \frac{17}{315}x^7 + \dots + \frac{B_{2n}4^n(4^n-1)}{(2n)!}x^{2n-1} + \dots$
 *
 * Implementacion:
 * Calcula la serie limitando la recomputacion de valores. Se implementa una 
 * actualizacion por recurrencia para el factorial y para las potencias de base 4 y x. 
 * El calculo de exponentes internos utiliza el metodo de exponenciacion binaria.
 * Se incluye un criterio de estabilizacion numerica ($\displaystyle \epsilon$).
 *
 * @par Entrada
 * - Un entero $\displaystyle n$ en el rango $\displaystyle 1 \leq n \leq 12$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle |x| < \frac{\pi}{2}$.
 *
 * @par Salida
 * Imprime:
 * @code
 * resultado: valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n^3)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, k, v, doble_i, exp;
    double x, sumatoria = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, base_v;
    double cuatro_elevado = 4.0, el_factorial = 1.0, x_elevada, termino;
    double epsilon = 1e-8;

    do {
        printf("Ingrese n (1 a 12) y x (|x| < 1.570796): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || n > 12 || fabs(x) >= 1.570796327);

    /* inicializacion de x_elevada para la recurrencia O(1) */
    x_elevada = x;

    /* Bucle principal con estructura for (Regla de oro) */
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

        /* Ensamblaje del termino iterativo */
        termino = (num_bernoulli * cuatro_elevado * (cuatro_elevado - 1.0) / el_factorial) * x_elevada;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        sumatoria += termino;

        /* actualizacion de las potencias para la siguiente iteracion */
        cuatro_elevado *= 4.0;
        x_elevada *= (x * x);
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}