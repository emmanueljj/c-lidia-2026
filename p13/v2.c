#include<stdio.h>

int main(void){
    int n, i, j;
    double resultado=0.0f, den, numerador, x=0.0;

    do{
        printf("ingresa n, x:");
        scanf("%d %lf", &n,&x);
    } while (n<0 || x<0.5);
    

    for ( i = 1; i <=n; i++){
        numerador = 1;
        den = 1;
        for ( j = 0; j < i ; j++)
        {
            numerador*=x-1;
            den*=x;
        }
        resultado+=(float)numerador/(den*i);
    }
    printf("resultado: %f",resultado);
    return 0;
}