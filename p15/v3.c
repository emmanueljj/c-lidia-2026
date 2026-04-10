/**
 * @file v3.c
 * @brief Aproximacion de $\displaystyle a^x$ mediante la expansion $\displaystyle e^{x \ln a}$ ($\displaystyle \mathcal{O}(n)$).
 *
 * @details
 * Serie:
 * $\displaystyle a^x = 1 + x \ln a + \frac{(x \ln a)^2}{2!} + \frac{(x \ln a)^3}{3!} + \cdots$
 *
 * Implementacion:
 * Primero se aproxima el valor de $\displaystyle \ln(a)$. 
 * Posteriormente, se calcula la serie exponencial actualizando el termino 
 * mediante la multiplicacion iterativa del factor $\displaystyle \frac{x \ln a}{i}$.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un real $\displaystyle a$ en el dominio $\displaystyle a > 0.5$.
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
 */
#include<stdio.h>
#include <math.h>

int main(void){
    int n, i, j;
    float x;
    double resultado=1.0, termino, a, ln= 0.0,z;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do{
        printf("ingresa n, a, x:");
        scanf("%d %lf %f", &n,&a,&x);
    } while (n<1 || a<=0.5 );
    
    termino= (a-1.0)/a;
    
    /* Calcular ln(a) */
    for ( i = 1; i <=n; i++){
        ln+=termino/i;
        termino*=(a-1.0)/a;
        if (fabs(termino) < epsilon) break;
    }
    
    termino=1;
    z=(double)x*ln;
    
    /* Calcular e^(x ln a) */
    for (i = 1; i <= n; i++)
    {
        termino*=(z/i);
        resultado+=termino;
        if (fabs(termino) < epsilon) break;
    }
    
    printf("resultado: %f",resultado);
    return 0;
}