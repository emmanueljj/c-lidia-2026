/**
 * @file ln2_v3.c
 * @brief Aproximacion de $\displaystyle \ln(2)$ usando recurrencia continua y optimizacion pura ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie de Mercator (armonica alternada):
 * $\displaystyle \ln(2) = \sum_{i=1}^{\infty} (-1)^{i+1} \frac{1}{i} = 1 - \frac{1}{2} + \frac{1}{3} - \frac{1}{4} + \cdots$
 *
 * Este programa aproxima con n terminos:
 * $\displaystyle \ln(2) \approx \sum_{i=1}^{n} (-1)^{i+1} \frac{1}{i}$
 *
 * Implementacion:
 * - Se evita el uso de modulos (%) para la alternancia del signo.
 * - Se reemplaza por una recurrencia in-line pura para el signo ($\displaystyle signo = -signo$).
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
 * Es la version mas eficiente al operar solo con sumas e inversiones de signo directas,
 * logrando un balance perfecto entre velocidad y uso de memoria.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int n, k;
    double ln2 = 0.0, signo = 1.0;
    double epsilon = 1e-8;

    /* Validacion estricta de dominio */
    do {
        printf("Ingrese el numero de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Bucle principal optimizado */
    for (k = 1; k <= n; k++) {
        if (fabs(signo / k) < epsilon) {
            break;
        }

        ln2 += signo / k;    
        
        /* Inversion del signo por recurrencia */
        signo = -signo; 
    }
    
    /* Salida cruda del resultado */
    printf("%lf\n", ln2);

    return 0;
}