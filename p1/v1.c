
#include <stdio.h>

int main(void)
{
    int n, k, j, num;
    float ln2 = 0.0f;

    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        num = 1; 

        for (j = 0; j < k + 1; j++) {
            num *= -1;
        }

        ln2 += (float)num / k; 
    }

    printf("resultado: %f\n", ln2);

    return 0;
}
