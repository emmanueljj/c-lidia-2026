/*
 * Archivo: v2.c
 * Aproximacion de (1/2)ln((1+x)/(1-x)) con serie de Maclaurin.
 * Nivel 2: Incluye validacion de dominio, estabilizacion numerica (Epsilon)
 * y estructura principal for.
 */
#include <stdio.h>
#include <math.h>

int main(void){
    int n, i, j;
    float x;
    double resultado = 0.0, num, termino;
    double epsilon = 1e-8;

    /* Validacion de dominio */
    do {
        printf("ingresa n, x:");
        scanf("%d %f", &n, &x);
    } while (n < 0 || x <= -1.0 || x >= 1.0);

    /* Bucle principal con estructura for */
    for (i = 0; i <= n; i++) {
        num = 1.0;
        j = 0;
        
        /* Ciclo interno para calcular la potencia */
        while (j < 2*i + 1) {
            num *= x;
            j++;
        }
        
        termino = num / (2.0 * i + 1.0);

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
    }
    
    printf("resultado: %f\n", resultado);
    return 0;
}