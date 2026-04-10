/*
 * Archivo: v2.c
 * Aproximacion de ln(x) mediante serie de potencias.
 * Nivel 2: Incluye validacion de dominio, estabilizacion numerica (Epsilon)
 * y estructura principal for.
 */
#include <stdio.h>
#include <math.h>

int main(void){
    int n, i, j;
    double resultado = 0.0, den, numerador, termino, x = 0.0;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do{
        printf("ingresa n, x:");
        scanf("%d %lf", &n, &x);
    } while (n < 0 || x < 0.5);
    
    /* Bucle principal con estructura for */
    for (i = 1; i <= n; i++) {
        numerador = 1.0;
        den = 1.0;
        j = 0;
        
        /* Ciclo interno con while para balancear estructuras */
        while (j < i) {
            numerador *= (x - 1.0);
            den *= x;
            j++;
        }
        
        termino = numerador / (den * i);

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
    }
    
    printf("resultado: %f\n", resultado);
    return 0;
}