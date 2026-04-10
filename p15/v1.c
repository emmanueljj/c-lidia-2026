/*
 * Archivo: v1.c
 * Aproximacion de a^x mediante la composicion con e^(x ln a).
 * Nivel 1: Calculo por separacion de variables.
 *
 * Detalles:
 * El programa calcula primero la aproximacion de ln(a).
 * Posteriormente, evalua la serie exponencial calculando el numerador
 * y el denominador de manera separada en cada iteracion.
 */
#include <stdio.h>

int main(void) {
  int n, i, j;
  float x;
  double resultado = 1.0, termino, a, ln = 0.0, num, den;

  printf("ingresa n, a, x:");
  scanf("%d %lf %f", &n, &a, &x);

  termino = (a - 1.0) / a;

  /* Calcular ln(a) */
  for (i = 1; i <= n; i++) {
    ln += termino / i;
    termino *= (a - 1.0) / a;
  }

  num = x * ln;
  den = 1;

  /* Calcular e^(x ln a) iterando con while */
  for (i = 1; i <= n; i++) {
    den *= i;
    resultado += num / den;
    num *= x * ln;
  }

  printf("resultado: %f", resultado);
  return 0;
}