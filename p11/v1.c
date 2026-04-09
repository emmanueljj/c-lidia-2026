#include<stdio.h>

int main(void){
    int n, den,i,j;
    float x;
    double resultado=0.0f,num=1.0f;

    printf("ingresa n, x:");
    scanf("%d %f", &n,&x);

    for ( i = 0; i <=n; i++){
        num=1.0f;
        for ( j = 0; j < 2*i+1 ; j++)
        {
            num*=x;
        }
        den= 2*i + 1;
        resultado+=(float)num/den;
    }
    printf("resultado: %f",resultado);
    return 0;
}