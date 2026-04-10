/*
 * Archivo: v2.c
 * Aproximacion de (x+x^2)e^x mediante una sumatoria consolidada.
 * Nivel 2: Se integra la validacion de dominio, estabilizacion numerica (Epsilon)
 * y un bucle principal for.
 *
 * Detalles:
 * Se evalua la expresion consolidada (i^2 * x^i) / i!. Los componentes
 * se calculan con un ciclo interno while para equilibrar estructuras.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, j;
    double x, num, den, termino, resultado = 0.0;
    double epsilon = 1e-8;

    /* Validacion de dominio estricta */
    do {
        printf("Ingrese el numero de iteraciones (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);
    
    printf("Ingrese valor de x : ");
    scanf("%lf", &x);

    /* Bucle principal con estructura for (Regla de oro) */
    for (i = 1; i <= n; i++) {
        num = 1.0;
        den = 1.0;
        
        /* Ciclo interno con while para potencia y factorial */
        j = 1;
        while (j <= i) {
            num *= x;
            den *= j;
            j++;
        }
        
        /* Se aisla el termino usando el coeficiente i^2 */
        termino = (i * i * num) / den;

        /* Criterio de paro numerico */
        if (fabs(termino) < epsilon) {
            break;
        }

        resultado += termino;
    }
    
    printf("resultado: %lf\n", resultado);
    return 0;
}