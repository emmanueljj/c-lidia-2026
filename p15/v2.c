#include<stdio.h>
#include <math.h>


int main(void){
    int n, i, j;
    float x;
    double resultado=1.0, termino, a, ln= 0.0, num,den;
    /* Variable para la estabilizacion Nivel 2 */
    double tolerancia = 1e-8;

    do{
        printf("ingresa n, a, x:");
        scanf("%d %lf %f", &n,&a,&x);
    } while (n<1 || a<=0.5 );
    
    termino= (a-1.0)/a;
    
    /*calcular ln(a)*/
    for ( i = 1; i <=n; i++){
        ln+=termino/i;
        termino*=(a-1.0)/a;
        if (fabs(termino) < tolerancia) break;
    }

    num = x*ln;
    den =1;
    termino=0;
    for (i = 1; i <= n; i++)
    {
        den*= i;
        termino=num/den;
        resultado+=termino;
        num*= x*ln;
        if (fabs(termino) < tolerancia) break;
    }
    

    printf("resultado: %f",resultado);
    return 0;
}