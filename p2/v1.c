
#include <stdio.h>

int main(void)
{
    int n, k, j, signo,den;
    float ln2 = 0.0f;

    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    for (k = 0; k <= n+1; k++) {
     signo = -1; 
     den = 2*k+1;
        for (j = 0; j < k + 1; j++) {
         signo *= -1;
        }
        ln2 += (float) signo / den; 
    }

    printf("resultado: %f\n", ln2);

    return 0;
}
