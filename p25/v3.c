/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \arccos(x)$ evaluando la serie iterativa ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle \arccos(x) = \frac{\pi}{2} - \arcsen(x) = \frac{\pi}{2} - \left( x + \frac{1}{2}\frac{x^3}{3} + \frac{1 \cdot 3}{2 \cdot 4}\frac{x^5}{5} + \cdots \right)$
 *
 * Implementacion:
 * Calcula la serie actualizando la fraccion de coeficientes y la potencia de x 
 * mediante multiplicacion iterativa. No utiliza ciclos internos. El resultado de 
 * la serie se resta de la constante de pi medios.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle |x| < 1$.
 *
 * @par Salida
 * Imprime:
 * @code
 * valor_flotante
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double x, sumatoria, fraccion_acumulada, x_elevada, termino_listo;
    double epsilon = 1e-8;

    do {
        printf("Introduce el valor para n y x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;
    
    fraccion_acumulada = 1.0;
    x_elevada = x;

    /* Bucle principal (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        
        /* Actualizacion por recurrencia */
        fraccion_acumulada *= (2.0 * i - 1.0) / (2.0 * i);
        x_elevada *= (x * x);

        sumatoria += fraccion_acumulada * (x_elevada / (2.0 * i + 1.0));
    }

    printf("%lf\n", 1.5707963267948966 - sumatoria);
    return 0;
}