/**
 * @file calcular_pi4.c
 * @brief Cálculo de la aproximación de pi/4 mediante la serie de Gregory-Leibniz.
 * @details Implementación optimizada que evita variables auxiliares para el signo 
 * o el denominador, calculándolos dinámicamente mediante aritmética modular.
 */

#include <stdio.h>

/**
 * @brief Punto de entrada principal del programa.
 * @return Retorna 0 al finalizar la ejecución exitosamente.
 */
int main(void)
{
    /* Declaración de variables:
     * n: Número total de iteraciones solicitadas por el usuario.
     * k: Variable iteradora para el ciclo.
     * Nota: Se elimina 'j' por falta de uso.
     */
    int n, k; 
    
    /* Acumulador para almacenar el resultado de pi/4 */
    float pi4 = 0.0f;

    /* Validación de dominio: 
     * Garantiza que el número de iteraciones no sea negativo.
     */
    do {
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    } while (n < 0);
    
    /* Bucle de sumatoria: 
     * Se ajusta el límite a 'k < n' para ejecutar exactamente 'n' iteraciones.
     */
    for (k = 0; k < n; k++) {
        /* * Cálculo y acumulación del enésimo término:
         * El signo se genera con (1 - 2*(k%2)):
         * - Si k es par   (ej. 0): (1 - 0) =  1 (Término positivo)
         * - Si k es impar (ej. 1): (1 - 2) = -1 (Término negativo)
         * El denominador impar se genera con (2*k + 1).
         */
        pi4 += (float) (1 - 2 * (k % 2)) / (2 * k + 1); 
    }

    /* Presentación de resultados */
    printf("Resultado: %f\n", pi4);

    return 0;
}