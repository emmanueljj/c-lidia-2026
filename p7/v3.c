/**
 * @file exp_v3.c
 * @brief Aproximacion de $\displaystyle e^x$ con serie de Maclaurin ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle e^x = \sum_{i=0}^{\infty} \frac{x^i}{i!}$
 *
 * Este programa aproxima con n terminos:
 * $\displaystyle e^x \approx \sum_{i=0}^{n} \frac{x^i}{i!}$
 *
 * Implementacion:
 * Se utiliza recurrencia para calcular el termino actual a partir del anterior,
 * multiplicando por x y dividiendo entre el nuevo indice.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 0$.
 * - Un real $\displaystyle x$.
 *
 * @par Salida
 * Imprime:
 * @code
 * valor_flotante
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 *
 * @note
 * Evita el calculo de factoriales y potencias desde cero en cada iteracion.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double x, resultado = 0.0, termino = 1.0;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do {
        printf("Ingrese el numero de iteraciones (n >= 0): ");
        scanf("%d", &n);
    } while (n < 0);

    printf("Ingrese valor de x: ");
    scanf("%lf", &x);

    /* Bucle principal */
    for (i = 0; i <= n; i++) {
        /* Acumulacion del termino */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
        
        /* Actualizacion por recurrencia */
        termino *= x / (i + 1.0);
    }

    /* Impresion del resultado final */
    printf("%lf\n", resultado);

    return 0;
}