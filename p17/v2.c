#include <stdio.h>
#include <math.h>

int main (void){
    int n, k, i, j;
    int signo;
    double resultado = 0.0;
    double den;

    do{
        printf("Cantidad de iteraciones y valor de k: ");
        scanf("%d %d", &n, &k);    
    } while (n<1 || k<0);
    

    for (i = 0; i < n; i++) {
        // calcular denominador con bucle
        den = 1.0;
        for (j = 0; j < (2*k+1); j++) {
            den *= (2*i + 1);
        }

        resultado += (double)(-1+2*(i%2))/ den;
    }

    printf("Resultado: %f\n", resultado);
    return 0;
}
