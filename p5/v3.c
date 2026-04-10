/**
 * @file serie_medios_v3.c
 * @brief Aproximacion de $\displaystyle \frac{1}{2}$ usando la serie de fracciones ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle \frac{1}{2} = \sum_{i=0}^{\infty} \frac{1}{(2i+1)(2i+3)}$
 *
 * Este programa aproxima con n terminos:
 * $\displaystyle \frac{1}{2} \approx \sum_{i=0}^{n-1} \frac{1}{(2i+1)(2i+3)}$
 *
 * Implementacion:
 * El denominador se calcula directamente en la instruccion de suma 
 * para reducir la asignacion de variables auxiliares.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
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
 * Se utiliza el formato de punto flotante (1.0 y 2.0) para asegurar la 
 * precision del calculo en la division.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double resultado = 0.0;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do {
        printf("Ingrese el numero de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Bucle principal */
    for (i = 0; i < n; i++) {
        /* Calculo del termino y acumulacion */
        if (fabs(1.0 / ((2.0 * i + 1.0) * (2.0 * i + 3.0))) < epsilon) {
            break;
        }

        resultado += 1.0 / ((2.0 * i + 1.0) * (2.0 * i + 3.0));
    }

    /* Impresion del resultado final */
    printf("%lf\n", resultado);

    return 0;
}