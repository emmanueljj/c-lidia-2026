#include <stdio.h>

double serie_cos(float x, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double fct = 1.0;
        // Calculo incremental para mejorar la estabilidad numerica
        for (int j = 1; j <= (2 * i); j++) {
            fct *= (x / j);
        }
        
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        suma += signo * fct;
    }
    return suma;
}

int main() {
    float x;
    int n;

    printf("Ingrese x: ");
    scanf("%f", &x);
    do {
        printf("Ingrese n: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Resultado: %f\n", serie_cos(x, n));
    return 0;
}