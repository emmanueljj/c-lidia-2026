/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \frac{1}{2} \ln \left( \frac{1+x}{1-x} \right)$ evaluando la serie ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle \frac{1}{2} \ln \left( \frac{1+x}{1-x} \right) = x + \frac{x^3}{3} + \frac{x^5}{5} + \frac{x^7}{7} + \cdots$
 *
 * Implementacion:
 * Se calcula la serie utilizando recurrencia para el numerador. El valor de la 
 * potencia se actualiza multiplicando por $\displaystyle x^2$ en cada iteracion.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 0$.
 * - Un real $\displaystyle x$ en el dominio $\displaystyle -1 < x < 1$.
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
 * Se reduce la cantidad de operaciones al evitar el calculo de la potencia 
 * desde cero en cada termino de la sumatoria.
 */
#include<stdio.h>
#include <math.h>

int main(void){
    int n, den, i, j;
    float x;
    double resultado = 0.0f, num;
    double epsilon = 1e-8;

    do{
        printf("ingresa n, x:");
        scanf("%d %f", &n, &x);
    } while (n < 0 || x <= -1.0 || x >= 1.0);

    num = x;
    for (i = 0; i <= n; i++){
        den = 2*i + 1;
        if (fabs((float)num / den) < epsilon) {
            break;
        }

        resultado += (float)num / den;
        num *= x * x; /* Actualizacion por recurrencia */
    }
    
    printf("resultado: %f", resultado);
    return 0;
}