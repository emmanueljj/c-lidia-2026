/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \sinh(x)$ empleando la serie de Maclaurin ($\displaystyle \mathcal{O}(n)$).
 *
 * @details 
 * La serie de Maclaurin para el seno hiperbolico esta dada por:
 * $\displaystyle \sinh(x) = \sum_{i=1}^{\infty} \frac{x^{2i-1}}{(2i-1)!} = x + \frac{x^3}{3!} + \frac{x^5}{5!} + \cdots$
 *
 * En esta implementacion, se recorren los indices de forma continua hasta $2n$.
 * Para evitar bucles anidados en el calculo de potencias y factoriales, 
 * estos valores se actualizan en cada iteracion. Solo se acumulan en el 
 * resultado aquellos terminos correspondientes a los indices impares.
 * Adicionalmente, cuenta con un mecanismo de estabilizacion numerica.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle x$.
 *
 * @par Salida
 * Imprime:
 * @code
 * Resultado: [valor_flotante]
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 */
#include <stdio.h>
#include <math.h>

int main (void){
    /* Declaracion de variables manteniendo los nombres originales */
    int n, i;
    double resultado = 0.0, den = 1.0, num = 1.0, x;
    double epsilon = 1e-8; /* Tolerancia de estabilizacion numerica */

    /* Validacion de dominio estricta */
    do {   
        printf("Cantidad de iteraciones y valor de x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    /* Se itera hasta n*2 porque, al ignorar los numeros pares,
       el bucle debe recorrer el doble de distancia para lograr 
       recolectar exactamente 'n' terminos impares. */
    for (i = 1; i <= n * 2; i++) {
        /* Actualizacion continua de la potencia y el factorial por recurrencia */
        num *= x; 
        den *= i;
        
        /* Se evaluan y suman solo los terminos en posiciones impares */
        if (i % 2 != 0) {
            /* 1. Evaluar estabilizacion antes de sumar */
            if (fabs(num / den) < epsilon) {
                break;
            }
            /* 2. Acumular segun la logica original */
            resultado += num / den;
        }
    }

    /* Salida descriptiva */
    printf("\nResultado: %f\n", resultado);
    return 0;
}
