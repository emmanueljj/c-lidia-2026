
#include <stdio.h>

int main(void)
{
    int x,n, i, j, num, den,decremento;
    float resultado = 0.0f;

    do{
        printf("Ingrese el numero de iteraciones : ");
        scanf("%d", &n);
    } while (n<0);
    
    printf("Ingrese valor de x : ");
    scanf("%d", &x);

    for (i = 0; i <= n; i++) {
        for(j=i,num=1,den=1;j>0;j--){
            den*=(j);
            num*=x;
        }
        resultado+=(float)num/den;
    }
    printf("\n%f",resultado);

    return 0;
}
