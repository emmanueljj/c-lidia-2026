#include <stdio.h>

int main(void){

    int n,i, denominador;
    float resultado = 0.0f;  

    printf("ingresa el nummero  de terminos: ");
    scanf("%d",&n);

    for ( i = 0; i <= n; i++){
        denominador = (2*i+1)*(2*i+3);
        resultado+=(float)1/denominador;
    }
    printf("resultado: %f",resultado);
    return 0;
}