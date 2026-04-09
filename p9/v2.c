#include <stdio.h>
/*con la version mas pulida de e^x*/
int main(void)
{
    int x,n, i, j, num=1, den=1;
    float resultado = 0.0f;

    do{
        printf("Ingrese el numero de iteraciones : ");
        scanf("%d", &n);
    } while (n<0);
    
    printf("Ingrese valor de x : ");
    scanf("%d", &x);

    for (i=1; i<=n ; i++) {
        num *= x;
        den*=(i<2)?1:(i);
        resultado+=(float)i*i*num/den;
    }
    printf("resultado: %f",resultado);
    return 0;
}
