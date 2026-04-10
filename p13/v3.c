/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \ln(x)$ evaluando la serie iterativa ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle \ln(x) = \left(\frac{x-1}{x}\right) + \frac{1}{2}\left(\frac{x-1}{x}\right)^2 + \frac{1}{3}\left(\frac{x-1}{x}\right)^3 + \cdots$
 *
 * Implementacion:
 * Se calcula la serie actualizando el termino base multiplicando por 
 * el factor $\displaystyle \frac{x-1}{x}$ en cada iteracion del bucle principal.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 0$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle x \geq \frac{1}{2}$.
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
 * Evita el calculo de la potencia desde cero en cada termino de la sumatoria.
 */
#include<stdio.h>
#include <math.h>

int main(void){
    int n, i, j;
    double resultado=0.0, termino, x;
    double epsilon = 1e-8;

    do{
        printf("ingresa n, x:");
        scanf("%d %lf", &n,&x);
    } while (n<0 || x<0.5);
    
    termino = (x-1.0)/x;

    for ( i = 1; i <=n; i++){
        if (fabs(termino/i) < epsilon) {
            break;
        }

        resultado += termino/i;
        termino *= (x-1.0)/x; /* Actualizacion por recurrencia */
    }
    printf("resultado: %f",resultado);
    return 0;
}