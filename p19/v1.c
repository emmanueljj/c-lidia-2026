/*
 * Archivo: v1.c
 * Aproximacion de sen(x) con serie de Maclaurin.
 * Nivel 1: Calculo de potencia y factorial desde cero en ciclos independientes.
 *
 * Detalles:
 * Para cada termino de la sumatoria, se determina el signo algebraico, 
 * y posteriormente se calculan el numerador (potencia) y el denominador 
 * (factorial) de manera separada mediante ciclos internos.
 */
#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j, signo;
    double resultado = 0.0, den, num;
    float x;

    printf("Cantidad de iteraciones y valor de k: ");
    scanf("%d %f", &n, &x);

    for (i = 0; i <= n; i++) {
        signo = (1 - 2 * (i % 2));
        num = 1;
        
        /* calculo de numerador con ciclo while */
        j = 1;
        while (j <= 2 * i + 1) {
            num *= x;
            j++;
        }   
        
        den = 1;
        /* calculo de denominador con ciclo while */
        j = 1;
        while (j <= 2 * i + 1) {
            den *= j;
            j++;
        } 
        
        resultado += (signo * num) / den;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}