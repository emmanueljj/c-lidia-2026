/*
 * Archivo: v2.c
 * Aproximacion de a^x integrando estabilizacion de error.
 * Nivel 2: Incluye validacion de dominio y estructuras iterativas principales for.
 *
 * Detalles:
 * Se restringe la entrada de iteraciones 'n' y la base 'a'.
 * Los bucles incluyen un criterio de paro numerico mediante una tolerancia
 * evaluada con la funcion fabs().
 */
#include <stdio.h>
#include <math.h>

int main(void){
    int n, i;
    float x;
    double resultado = 1.0, termino, a, ln = 0.0, num, den;
    double tolerancia = 1e-8;

    /* Validacion de dominio */
    do{
        printf("ingresa n, a, x:");
        scanf("%d %lf %f", &n, &a, &x);
    } while (n < 1 || a <= 0.5);
    
    termino = (a - 1.0) / a;
    
    /* Calcular ln(a) iterando con for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        ln += termino / i;
        termino *= (a - 1.0) / a;
        if (fabs(termino) < tolerancia) break;
    }

    num = x * ln;
    den = 1.0;
    termino = 0.0;
    
    /* Calcular e^(x ln a) con for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        den *= i;
        termino = num / den;
        resultado += termino;
        num *= x * ln;
        if (fabs(termino) < tolerancia) break;
    }
    
    printf("resultado: %f\n", resultado);
    return 0;
}