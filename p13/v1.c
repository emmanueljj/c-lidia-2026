#include<stdio.h>

int main(void){
    int n, den,i,j,numerador;
    float x;
    double resultado=0.0f;

    printf("ingresa n, x:");
    scanf("%d %f", &n,&x);

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