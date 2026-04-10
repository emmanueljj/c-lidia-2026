/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle (x+x^2)e^x$ evaluando la serie base ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle (x+x^2)e^x = x + \frac{4x^2}{2!} + \frac{9x^3}{3!} + \frac{16x^4}{4!} + \cdots$
 *
 * Implementacion:
 * Se calcula la serie de Maclaurin estandar de $\displaystyle e^x = \sum_{i=0}^{n} \frac{x^i}{i!}$ 
 * y el resultado final se multiplica por el factor $\displaystyle (x+x^2)$ para obtener 
 * el resultado de la funcion compuesta con un solo ciclo.
 * Incluye un criterio de estabilizacion numerica ($\displaystyle \epsilon$).
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 0$.
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
 *
 * @note
 * El uso de la factorizacion algebraica fuera del bucle permite evaluar
 * la funcion compuesta manteniendo la complejidad computacional base de exp(x).
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i;
    double x, num = 1.0, den = 1.0, termino;
    double epsilon = 1e-8;
    double resultado = 0.0;

    do {
        printf("Ingrese el numero de iteraciones (n >= 0): ");
        scanf("%d", &n);
    } while (n < 0);
    
    printf("Ingrese valor de x : ");
    scanf("%lf", &x);

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 0; i <= n; i++) {
        
        /* Actualizacion por recurrencia para la serie estandar de e^x */
        if (i > 0) {
            num *= x;
            den *= i;
        }
        
        termino = num / den;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
    }
    
    /* Se multiplica el resultado estandar de e^x por (x + x^2) */
    printf("resultado: %lf\n", resultado * (x + x * x));
    return 0;
}