#include<stdio.h>

int main(void){
    int n, i, j;
    float x;
    double resultado=1.0, termino, a, ln= 0.0, num,den;

    printf("ingresa n, a, x:");
    scanf("%d %lf %f", &n,&a,&x);
    
    termino= (a-1.0)/a;
    
    /*calcular ln(a)*/
    for ( i = 1; i <=n; i++){
        ln+=termino/i;
        termino*=(a-1.0)/a;
    }

    num = x*ln;
    den =1;
    for (i = 1; i <= n; i++)
    {
        den*= i;
        resultado+=num/den;
        num*= x*ln;
    }
    

    printf("resultado: %f",resultado);
    return 0;
}