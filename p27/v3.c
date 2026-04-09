#include <stdio.h>
#include <math.h>

int main (void){
    int n, i, j;
    double resultado = 0.0, den=1, num=1,x;

    do{   
        printf("Cantidad de iteraciones y valor de x: ");
        scanf("%d %lf", &n, &x);
    } while (n<1);

/* Se itera hasta n*2 porque, al ignorar los numeros pares,
 el bucle debe recorrer el doble de distancia para lograr 
 recolectar exactamente 'n' terminos impares. */
 
    for (i = 1; i <= n*2; i++) {
        num*=x; 
        den*=i;
        /*modulo para sumar solo los terminos impares */
        resultado+= i%2?num/den:0;
    }

    printf("\nResultado: %f\n", resultado);
    return 0;
}
