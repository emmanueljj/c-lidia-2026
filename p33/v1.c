#include <stdio.h>

int main(void) {
    int n, i, j, exponente;
    double x, u = 0.0, sumatoria = 1.0, numerador, denominador, signo;

    scanf("%d %lf", &n, &x);

    /*bucle para calcular u = sin(x)*/
    for (i = 1; i <= n; i++) {
        exponente = 2 * i - 1;

        /*calcula potencias de x*/
        numerador = 1.0;
        for (j = 0; j < exponente; j++) {
            numerador *= x;
        }

        /*calcula factoriales*/
        denominador = 1.0;
        for (j = 1; j <= exponente; j++) {
            denominador *= j;
        }

        /*determina el signo alterno*/
        signo = (i % 2 == 0) ? -1.0 : 1.0;

        u += signo * (numerador / denominador);
    }

    /*bucle para calcular e^u*/
    for (i = 1; i <= n; i++) {
        
        /*calcula potencias de u*/
        numerador = 1.0;
        for (j = 0; j < i; j++) {
            numerador *= u;
        }

        /*calcula factoriales*/
        denominador = 1.0;
        for (j = 1; j <= i; j++) {
            denominador *= j;
        }

        /*ensambla el termino de e^u*/
        sumatoria += numerador / denominador;
    }

    printf("%lf\n", sumatoria);
    return 0;
}