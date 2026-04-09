#include<stdio.h>
#include <math.h>

int main(void){
    int n, i, j;
    float x;
    double resultado=1.0, termino, a, ln= 0.0,z;
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
    termino=1;
    z=(double)x*ln;
    for (i = 1; i <= n; i++)
    {
        termino*=(z/i);
        resultado+=termino;
        if (fabs(termino) < tolerancia) break;
    }
    

    printf("resultado: %f",resultado);
    return 0;
}