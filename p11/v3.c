#include<stdio.h>

int main(void){
    int n, den,i,j;
    float x;
    double resultado=0.0f,num;

    do{
        printf("ingresa n, x:");
        scanf("%d %f", &n,&x);
    } while (n < 0 || x <= -1.0 || x >= 1.0);

    num=x;
    for ( i = 0; i <=n; i++){
        den= 2*i + 1;
        resultado+=(float)num/den;
        num*=x*x;
    }
    printf("resultado: %f",resultado);
    return 0;
}
