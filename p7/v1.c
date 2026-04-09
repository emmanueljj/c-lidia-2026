
#include <stdio.h>

int main(void)
{
    int x,n, i, j, num, den,decremento;
    float resultado = 0.0f;

    printf("Ingrese el numero de iteraciones : ");
    scanf("%d", &n);
    printf("Ingrese valor de x : ");
    scanf("%d", &x);

    for (i = 0; i <= n; i++) {
        num = 1;
        for(j=1;j<=i;j++){
            num*=x;
        }
        den=1;
        for(j=i;j>0;j--){
            den*=(j);
        }
        resultado+=(float)num/den;
    }
    printf("\n%f",resultado);

    return 0;
}
