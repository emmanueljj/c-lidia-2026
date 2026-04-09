#include<stdio.h>

int main(void){
    int n, i, j;
    double resultado=0.0, termino, x;

    do{
        printf("ingresa n, x:");
        scanf("%d %lf", &n,&x);
    } while (n<0 || x<0.5);
    
    termino= (x-1.0)/x;

    for ( i = 1; i <=n; i++){
        resultado+=termino/i;
        termino*=(x-1.0)/x;
    }
    printf("resultado: %f",resultado);
    return 0;
}