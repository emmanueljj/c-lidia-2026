/**
 * @file calcular_ln2_optimizado.c
 * @brief Cálculo de la aproximación de ln(2) mediante serie armónica alternada.
 * @details Implementación optimizada que evita el uso de librerías externas (como math.h) 
 * y variables de estado auxiliares para el signo. La alternancia se logra dinámicamente 
 * mediante operaciones aritméticas modulares.
 */

#include <stdio.h>

/**
 * @brief Punto de entrada principal del programa.
 * @return Retorna 0 al finalizar la ejecución exitosamente.
 */
int main(void)
{
    /* Declaración de variables:
     * n: Número total de iteraciones (límite superior de la sumatoria).
     * k: Variable iteradora y denominador actual en la serie.
     * Nota: Se omite la variable 'j' original por falta de uso.
     */
    int n, k;
    
    /* Acumulador de punto flotante para almacenar el resultado de la sumatoria */
    float ln2 = 0;
    
    /* * Validación de dominio:
     * Se implementa un ciclo de control estricto do-while para garantizar 
     * que el usuario introduzca un valor entero N >= 1, evitando así 
     * divisiones por cero o cálculos inválidos.
     */
    do {
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    } while (n < 1);
    

    /* Bucle de sumatoria (Desarrollo en serie) */
    for (k = 1; k <= n; k++)
    {
        /* * Cálculo y acumulación del enésimo término:
         * El signo se deduce algorítmicamente mediante la expresión (-1 + 2*(k%2)):
         * - Si 'k' es impar (k%2 == 1): (-1 + 2) =  1 (Término se suma).
         * - Si 'k' es par   (k%2 == 0): (-1 + 0) = -1 (Término se resta).
         */
        ln2 += (float)(-1 + 2 * (k % 2)) / k;    
    }
    
    /* Presentación de resultados al usuario */
    printf("Resultado: %f\n", ln2);

    return 0;
}