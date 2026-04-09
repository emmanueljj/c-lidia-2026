#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j,signo;
    double resultado = 0.0, den, num;
    float x;


    printf("Cantidad de iteraciones y valor de k: ");
    scanf("%d %f", &n, &x);

    for (i = 0; i <= n; i++) {
        signo=(1-2*(i%2));     /*se puede calcular con bucle pero seria aun peor*/
        num=1;
        /*calcula numerador*/
        for ( j = 1; j <= 2*i+1; j++){
            num*=x;
        }   
        den=1;
        for ( j = 1; j <= 2*i+1; j++){
            den*=j;
        } 
        resultado+=(signo*num)/den;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}
