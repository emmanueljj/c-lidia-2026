/**
 * @file v3.c
 * @brief Calculo de la sumatoria parcial para los Numeros de Euler
 * ($\displaystyle \mathcal{O}(n \cdot k)$).
 *
 * @details
 * Formula completa de los Numeros de Euler:
 * $\displaystyle E_k = \frac{2^{2k+2}(2k)!}{\pi^{2k+1}} \left\{ 1 -
 * \frac{1}{3^{2k+1}} + \frac{1}{5^{2k+1}} - \cdots \right\}$
 *
 * Este programa aproxima unicamente la serie de la llave con n terminos:
 * $\displaystyle S_n = \sum_{i=0}^{n-1} \frac{(-1)^i}{(2i+1)^{2k+1}}$
 *
 * Implementacion:
 * El denominador se calcula en cada iteracion mediante un bucle interno,
 * debido a que la base $\displaystyle (2i+1)$ cambia por termino. Incluye
 * validacion de dominio, limpieza de buffer y estabilizacion numerica.
 *
 * @par Entrada
 * - Un entero $\displaystyle n \geq 1$.
 * - Un entero $\displaystyle k \geq 0$.
 *
 * @par Salida
 * Imprime:
 * @code
 * resultado: valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: $\displaystyle \mathcal{O}(n \cdot k)$. Memoria: $\displaystyle
 * \mathcal{O}(1)$.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, k, i, j;
  double resultado = 0.0;
  double den, termino;
  double epsilon = 1e-8;

  /* Validacion de dominio */
  do {
    printf("Cantidad de iteraciones (n>=1) y valor de k (k>=0): ");
    scanf("%d %d", &n, &k);
  } while (n < 1 || k < 0);

  /* Bucle principal de la sumatoria */
  for (i = 0; i < n; i++) {

    /* Calcular el denominador */
    den = 1.0;
    for (j = 0; j < (2 * k + 1); j++) {
      den *= (2 * i + 1);
    }

    /* Calcular el termino a sumar */
    termino = (double)(1 - 2 * (i % 2)) / den;

    /* Acumular el resultado */
    resultado += termino;

    /* Estabilizacion por paro anticipado */
    if (fabs(termino) < epsilon) {
      break;
    }
  }

  /* Salida final */

  printf("resultado: %lf\n", resultado);

  return 0;
}