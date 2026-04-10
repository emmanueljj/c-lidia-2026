/**
 * @file serie_basilea_v3.c
 * @brief Aproximacion de $\displaystyle \frac{\pi^2}{6}$ usando la serie de Basilea ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie de Basilea:
 * $\displaystyle \frac{\pi^2}{6} = \sum_{i=1}^{\infty} \frac{1}{i^2} = 1 + \frac{1}{2^2} + \frac{1}{3^2} + \frac{1}{4^2} + \cdots$
 *
 * Este programa aproxima con n terminos:
 * $\displaystyle \frac{\pi^2}{6} \approx \sum_{i=1}^{n} \frac{1}{i^2}$
 *
 * Implementacion:
 * - Se elimina la creacion de variables auxiliares para el denominador.
 * - El calculo del cuadrado y la division se realizan in-line para maximizar 
 * el rendimiento computacional.
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
 * Es la version mas limpia computacionalmente. El casteo a double garantiza 
 * que no ocurran divisiones enteras truncadas a cero.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int n, k;
    double epsilon = 1e-8;
    double resultado = 0.0;

    /* Validacion de dominio */
    do {
        printf("Ingrese el numero de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Bucle principal optimizado */
    for (k = 1; k <= n; k++) {
        if (fabs(1.0 / ((double)k * k)) < epsilon) {
            break;
        }

        resultado += 1.0 / ((double)k * k);
    }

    printf("%lf\n", resultado);

    return 0;
}