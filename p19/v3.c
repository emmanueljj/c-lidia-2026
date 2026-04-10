/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle \sen(x)$ evaluando la serie paso a paso ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie de Maclaurin:
 * $\displaystyle \sen(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \cdots$
 *
 * Implementacion:
 * Se itera de forma progresiva acumulando potencias y factoriales en cada paso.
 * Un condicional basado en la paridad del iterador determina cuando el termino 
 * actual corresponde a una potencia impar de la serie, procediendo a sumarlo
 * al resultado y a invertir el signo del numerador.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle x$.
 *
 * @par Salida
 * Imprime:
 * @code
 * Resultado: valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n)$. Memoria: $\displaystyle \mathcal{O}(1)$.
 *
 * @note
 * Evita el calculo desde cero de las potencias y factoriales. La salida 
 * incluye la impresion de trazas para diagnostico en cada ciclo interno.
 */
#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j;
    double resultado = 0.0, den = 1, num = 1, x;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do {   
        printf("Cantidad de iteraciones y valor de x: ");
        scanf("%d %lf", &n, &x);
    } while (n < 1);

    /* Bucle principal evaluando hasta 2n */
    for (i = 1; i <= n * 2; i++) {
        num *= x; 
        den *= i;
        
        if (i % 2) {
            if (fabs(num / den) < epsilon) {
            break;
        }

        resultado += num / den;
            num *= -1;
        }
    }

    printf("\nResultado: %f\n", resultado);
    return 0;
}