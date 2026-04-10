/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \tan(x)$ con serie de Maclaurin ($\displaystyle \mathcal{O}(n^3)$).
 *
 * @details
 * Serie:
 * $\displaystyle \tan(x) = x + \frac{x^3}{3} + \frac{2x^5}{15} + \dots + \frac{B_{2n}(-4)^n(1-4^n)}{(2n)!}x^{2n-1} + \dots$
 *
 * Implementacion:
 * Calcula la serie limitando la recomputacion de valores. Se implementa una 
 * actualizacion por recurrencia para el factorial y para las potencias de x. 
 * El calculo de exponentes internos utiliza el metodo de exponenciacion binaria.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle |x| < \frac{\pi}{2}$.
 *
 * @par Salida
 * Imprime:
 * @code
 * resultado: valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n^3)$ debido al calculo explicito de los Numeros de Bernoulli. Memoria: $\displaystyle \mathcal{O}(1)$.
 *
 * @note
 * El costo computacional es dictado por la sumatoria doble requerida para
 * calcular la constante de Bernoulli sin utilizar un arreglo de almacenamiento.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    /* Declaracion de variables iniciales */
    int n, i, k, v, doble_i, exp;
    double x, resultado_total = 0.0, num_bernoulli, suma_interna, combinatoria, signo_v, v_elevado, base_v;
    double epsilon = 1e-8;
    double cuatro_elevado = 1.0, el_factorial = 1.0, x_elevada;

    /* Validacion de dominio */
    do {
        printf("Ingresa n (1 a 12) y x (|x| < 1.570796): ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || n > 12 || fabs(x) >= 1.570796);

    x_elevada = x; 

    /* Bucle principal */
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
                
                /* Exponenciacion binaria para v^(2i) */
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

        /* Actualizacion de terminos por recurrencia */
        cuatro_elevado *= 4.0;
        el_factorial *= doble_i * (doble_i - 1.0); 

        /* Ensamble del termino y acumulacion */
        resultado_total += (num_bernoulli * ((i % 2 != 0) ? -cuatro_elevado : cuatro_elevado) * (1.0 - cuatro_elevado) / el_factorial) * x_elevada;
        
        /* Prepara x para la siguiente iteracion */
        x_elevada *= (x * x); 
    }

    printf("\nresultado: %lf\n", resultado_total);
    return 0;
}