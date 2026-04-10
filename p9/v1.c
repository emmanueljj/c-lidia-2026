/*
 * Archivo: v1.c
 * Aproximacion de (x+x^2)e^x usando dos sumatorias independientes.
 * Nivel 1: Calculo directo de potencias y factoriales desde cero.
 *
 * Detalles:
 * Se divide la expresion de la funcion en xe^x + x^2e^x.
 * Se utilizan ciclos internos while para calcular el numerador y el denominador
 * de forma separada en cada sumatoria, corrigiendo los tipos de datos a double.
 */
#include <stdio.h>

int main(void)
{
    int n, i, j;
    double x, num, den;
    double resultado = 0.0;

    printf("Ingrese el numero de iteraciones : ");
    scanf("%d", &n);
    printf("Ingrese valor de x : ");
    scanf("%lf", &x); /* Se lee como double */

    /* Primera sumatoria: x * e^x (Regla de oro: for) */
    for (i = 0; i <= n; i++) {
        num = 1.0;
        den = 1.0;
        
        j = 1;
        while (j <= i + 1) {
            num *= x;
            j++;
        }
        
        j = i;
        while (j > 0) {
            den *= j;
            j--;
        }
        
        resultado += num / den;
    }
    
    /* Segunda sumatoria: x^2 * e^x (Regla de oro: for) */
    for (i = 0; i <= n; i++) {
        num = 1.0;
        den = 1.0;
        
        j = 1;
        while (j <= i + 2) {
            num *= x;
            j++;
        }
        
        j = i;
        while (j > 0) {
            den *= j;
            j--;
        }
        
        resultado += num / den;
    }
    
    printf("\n%lf\n", resultado);
    return 0;
}