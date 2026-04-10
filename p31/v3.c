/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \text{arctanh}(x)$ con serie de Maclaurin ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle \text{arctanh}(x) = x + \frac{x^3}{3} + \frac{x^5}{5} + \frac{x^7}{7} + \dots + \frac{x^{2n+1}}{2n+1} + \dots$
 *
 * Implementacion:
 * Se utiliza recurrencia para actualizar la potencia de x en cada iteracion
 * multiplicando por $\displaystyle x^2$, evitando bucles anidados. Se incluye
 * validacion de dominio y un criterio de estabilizacion numerica ($\displaystyle \epsilon$).
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle |x| < 1$.
 *
 * @par Salida
 * Imprime:
 * @code
 * resultado: valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double x, sumatoria, x_elevada, x_cuadrada, termino;
    double epsilon = 1e-8;

    /* Validacion de dominio (|x| < 1) */
    do {
        printf("Ingrese n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;
    
    x_elevada = x;
    x_cuadrada = x * x;

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        /* Actualizacion por recurrencia */
        x_elevada *= x_cuadrada;
        
        termino = x_elevada / (2.0 * i + 1.0);

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        sumatoria += termino;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}