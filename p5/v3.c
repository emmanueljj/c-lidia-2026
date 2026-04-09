#include <stdio.h>

int main(void){

    int n,i;    /*ya no se usa la variable denominador*/
    float resultado = 0.0f;  

    /*validacion*/
    do{
        printf("ingresa el nummero  de terminos: ");
        scanf("%d",&n);
    } while (n<0);
    
    for ( i = 0; i <= n; i++){
        resultado+=(float)1/((2*i+1)*(2*i+3));  /*el denomminador se calcula directamente*/
    }
    printf("resultado: %f",resultado);
    return 0;
}