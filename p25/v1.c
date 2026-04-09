#include <stdio.h>

int main(void) {
    int n, i, j;
    double x, sumatoria, prod_impar, prod_par, x_elevada, termino_listo;
    double pi_medios = 1.5707963267948966;

    printf("introduce el valor para n y x:",&n, &x);
    scanf("%d %lf", &n, &x);

    sumatoria = x;

    /*bucle principal para cada termino*/
    for (i = 1; i <= n; i++) {
        
        /*calcula el producto de los numeradores impares*/
        prod_impar = 1.0;
        for (j = 1; j <= i; j++) {
            prod_impar *= (2.0 * j - 1.0);
        }

        /*calcula el producto de los denominadores pares*/
        prod_par = 1.0;
        for (j = 1; j <= i; j++) {
            prod_par *= (2.0 * j);
        }

        /*calcula x elevada a la 2i+1*/
        x_elevada = 1.0;
        for (j = 0; j < (2 * i + 1); j++) {
            x_elevada *= x;
        }

        /*ensambla el termino*/
        termino_listo = (prod_impar / prod_par) * (x_elevada / (2.0 * i + 1.0));
        sumatoria += termino_listo;
    }

    printf("%lf\n", pi_medios - sumatoria);
    return 0;
}