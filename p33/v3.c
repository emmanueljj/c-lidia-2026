/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle e^{\sen(x)}$ mediante composicion de series ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle e^{\sen(x)} = 1 + x + \frac{x^2}{2} - \frac{x^4}{8} - \frac{x^5}{15} + \dots$
 *
 * Implementacion:
 * El programa aproxima el valor evaluando en dos etapas continuas.
 * Primero calcula $\displaystyle u = \sen(x)$ actualizando el termino de la serie 
 * trigonometrica con la proporcion $\displaystyle -x^2$. Posteriormente calcula 
 * $\displaystyle e^u$ multiplicando iterativamente por $\displaystyle \frac{u}{i}$.
 * Incluye un criterio de estabilizacion numerica ($\displaystyle \epsilon$) en ambos procesos.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle x$.
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
    double x, u, sumatoria = 1.0;
    double termino_sin, x_cuadrada, termino_exp;
    double epsilon = 1e-8;

    do {
        printf("Ingrese n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    termino_sin = x;
    x_cuadrada = x * x;
    u = x;

    /* Bucle principal para u = sen(x) (Regla de oro: for) */
    for (i = 1; i < n; i++) {
        /* recurrencia saltando impares. signo alterno se genera solo con el negativo de x_cuadrada */
        termino_sin *= -x_cuadrada / ((2.0 * i) * (2.0 * i + 1.0));
        
        if (fabs(termino_sin) < epsilon) {
            break;
        }
        
        u += termino_sin;
    }

    /* inicializacion para la serie exponencial */
    termino_exp = 1.0;

    /* Bucle principal para e^u (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        /* recurrencia in-line multiplicando fluidamente por u/i */
        termino_exp *= u / i;
        
        if (fabs(termino_exp) < epsilon) {
            break;
        }
        
        sumatoria += termino_exp;
    }

    printf("resultado: %lf\n", sumatoria);
    return 0;
}