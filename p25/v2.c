#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i, j;
    double x, sumatoria, prod_impar, prod_par, x_elevada, termino_listo;
    /*se borro "termino listo" y "pi_medios"*/

    /* Validacion de dominio (|x| < 1)  */
    do {
        scanf("%d %lf", &n, &x);
    } while (n < 1 || fabs(x) >= 1.0);

    sumatoria = x;

    for (i = 1; i <= n; i++) {
        prod_impar = 1.0;
        prod_par = 1.0;
        
        /*se usan 2 ciclos*/
        for (j = 1; j <= i; j++){
        prod_impar *= (2.0 * j - 1.0);
        prod_par *= (2.0 * j);
        }    

        x_elevada = 1.0;
        for (j = 0; j < (2 * i + 1); j++) x_elevada *= x;

        sumatoria += (prod_impar / prod_par) * (x_elevada / (2.0 * i + 1.0));
    }

    printf("%lf\n", 1.5707963267948966 - sumatoria);
    return 0;
}