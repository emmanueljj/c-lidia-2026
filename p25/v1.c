/*
 * Archivo: v1.c
 * Aproximacion de arc cos(x) con serie de Maclaurin.
 * Nivel 1: Calculo de componentes mediante ciclos independientes.
 *
 * Detalles:
 * Se aproxima arc sen(x) calculando el producto de los numeradores impares,
 * el producto de los denominadores pares y las potencias de x mediante
 * ciclos internos separados. El resultado se resta de pi/2.
 */
#include <stdio.h>

int main(void) {
    int n, i, j;
    double x, sumatoria, prod_impar, prod_par, x_elevada, termino_listo;
    double pi_medios = 1.5707963267948966;

    printf("Introduce el valor para n y x: ");
    scanf("%d %lf", &n, &x);

    sumatoria = x;

    /* Bucle principal para cada termino (Regla de oro: for) */
    for (i = 1; i <= n; i++) {
        
        /* Calcula el producto de los numeradores impares con while */
        prod_impar = 1.0;
        j = 1;
        while (j <= i) {
            prod_impar *= (2.0 * j - 1.0);
            j++;
        }

        /* Calcula el producto de los denominadores pares con while */
        prod_par = 1.0;
        j = 1;
        while (j <= i) {
            prod_par *= (2.0 * j);
            j++;
        }

        /* Calcula x elevada a la 2i+1 con while */
        x_elevada = 1.0;
        j = 0;
        while (j < (2 * i + 1)) {
            x_elevada *= x;
            j++;
        }

        /* Ensambla el termino */
        termino_listo = (prod_impar / prod_par) * (x_elevada / (2.0 * i + 1.0));
        sumatoria += termino_listo;
    }

    printf("%lf\n", pi_medios - sumatoria);
    return 0;
}