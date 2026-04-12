#include <stdio.h>

int main() {
    int n, i, j;
    float x;
    double suma = 0.0, num;

    printf("Ingrese x: ");
    scanf("%f", &x);
    printf("Ingrese n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        // Calcula la potencia x^i desde cero para cada iteracion
        num = 1.0;
        for (j = 0; j < i; j++) {
            num *= x;
        }

        if (i % 2 == 0) suma -= num / i;
        else suma += num / i;
    }

    printf("Resultado: %f\n", suma);
    return 0;
}