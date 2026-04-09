#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j;
    double resultado = 0.0, den=1, num= 1,x;

    /*se agrega validacion de dominio*/
    do{   
        printf("Cantidad de iteraciones y valor de x: ");
        scanf("%d %lf", &n, &x);
    } while (n<1);


    for (i = 1; i <= n*2; i++) {
        num*=x; 
        den*=i;
        if(i%2){
            resultado+=num/den;
            num*=-1;
        }
        printf("\n%lf %lf %lf",num,den,resultado);
    }

    printf("\nResultado: %f\n", resultado);
    return 0;
}
