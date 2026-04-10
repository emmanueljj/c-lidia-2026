/*
 * Archivo: v1.c
 * Aproximacion de (1/2)ln((1+x)/(1-x)) con serie de Maclaurin.
 * Nivel 1: Calculo de potencia mediante un ciclo independiente.
 *
 * Detalles:
 * Se calcula el numerador multiplicando la variable x repetidamente
 * en un ciclo interno y se asigna el denominador en cada iteracion.
 */
#include<stdio.h>

int main(void){
    int n, den, i, j;
    float x;
    double resultado = 0.0f, num = 1.0f;

    printf("ingresa n, x:");
    scanf("%d %f", &n, &x);

    for (i = 0; i <= n; i++){
        num = 1.0f;
        j = 0;
        
        /* Ciclo interno para calcular la potencia */
        while (j < 2*i + 1) {
            num *= x;
            j++;
        }
        
        den = 2*i + 1;
        resultado += (float)num / den;
    }
    
    printf("resultado: %f", resultado);
    return 0;
}