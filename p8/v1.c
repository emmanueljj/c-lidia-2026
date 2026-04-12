#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, num, den;

    printf("Ingrese x: ");
    scanf("%f", &x);
    printf("Ingrese n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        num = 1.0;
        for (j = 0; j < i; j++) num *= x;
        
        den = 1.0;
        for (j = 1; j <= i; j++) den *= j;
        
        suma += (i * num) / den;
    }

    printf("Resultado: %f\n", suma);
    return 0;
}