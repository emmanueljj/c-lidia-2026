#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j;
    double resultado = 0.0, den, num,x;

    /*se agrega validacion de dominio*/
    do{   
        printf("Cantidad de iteraciones y valor de k: ");
        scanf("%d %lf", &n, &x);
    } while (n<1);


    for (i = 0; i <= n; i++) {
        num=(1-2*(i%2));    /*ahora el numerador hace tambien la funcion del signo*/
        den=1;
        /*calcula numerador y denominador*/
        for ( j = 1; j <= 2*i+1; j++){
            num*=x;
            den*=j;
        }   
        resultado+=(num)/den;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}
