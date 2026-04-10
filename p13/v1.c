/*
 * Archivo: v1.c
 * Aproximacion de ln(x) mediante serie de potencias.
 * Nivel 1: Calculo por separacion de variables.
 *
 * Detalles:
 * Para cada iteracion, se calculan el numerador y el denominador
 * multiplicando los factores desde cero mediante un ciclo interno.
 */
#include<stdio.h>

int main(void){
    int n, i, j;
    float x;
    double resultado=0.0f,den,numerador;

    printf("ingresa n, x:");
    scanf("%d %f", &n,&x);

    for ( i = 1; i <=n; i++){
        numerador = 1;
        den = 1;
        j = 0;
        
        /* Ciclo interno para calcular las potencias */
        while ( j < i )
        {
            numerador *= x-1;
            den *= x;
            j++;
        }
        
        resultado += (float)numerador/(den*i);
    }
    printf("resultado: %f",resultado);
    return 0;
}