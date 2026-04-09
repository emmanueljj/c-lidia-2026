/**
 * @file euler_sumatoria_nv3.c
 * @brief Calculo estabilizado de la sumatoria parcial para los Numeros de Euler.
 *
 * @details
 * Nivel 3: Implementacion unificada en main().
 * Debido a que la base del denominador cambia en cada termino (1, 3, 5...),
 * se utiliza un bucle anidado con complejidad O(n*k) para calcular el 
 * denominador explicitamente, apegandose a las metodologias del curso.
 * Incluye validacion de dominio estricta, manejo de desbordamiento (double) 
 * y estabilizacion de la solucion (paro anticipado).
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int n, k, i, j;
    double resultado = 0.0;
    double den, termino;
    double tolerancia = 1e-8; /* Variable para la estabilizacion Nivel 2 */

    printf("--- Calculadora Serie Euler (Sumatoria Parcial) ---\n");

    /* Nivel 2: Validacion de dominio estricta y a prueba de caracteres */
    do {
        printf("Cantidad de iteraciones (n>=1) y valor de k (k>=0): ");
        if (scanf("%d %d", &n, &k) != 2 || n < 1 || k < 0) {
            printf("[!] Error: Entradas invalidas. Verifique el dominio.\n");
            
            /* Limpieza del buffer para evitar bucles infinitos si el usuario teclea letras */
            while(getchar() != '\n'); 
            n = 0; 
        }
    } while (n < 1 || k < 0);
    
    /* Bucle principal de la sumatoria */
    for (i = 0; i < n; i++) {
        
        /* 1. Calcular el denominador con bucle anidado O(n*k) */
        den = 1.0;
        for (j = 0; j < (2 * k + 1); j++) {
            den *= (2 * i + 1);
        }

        /* 2. Calcular el termino a sumar
         * Nota: Se ajusto el generador de signos a (1 - 2*(i%2)) 
         * para que la serie inicie en positivo (1, -1, 1, -1...) */
        termino = (double)(1 - 2 * (i % 2)) / den;
        
        /* 3. Acumular el resultado */
        resultado += termino;

        /* Nivel 2 y 3: Estabilizacion (Paro anticipado) */
        if (fabs(termino) < tolerancia) {
            printf("\n[*] Info: La sumatoria convergio prematuramente en la iteracion %d.\n", i);
            break;
        }
    }

    /* Salida limpia */
    printf("\n[Resultado Final]\n");
    printf("> Iteraciones evaluadas : %d\n", i < n ? i + 1 : n);
    printf("> Resultado             : %.8lf\n", resultado);

    return EXIT_SUCCESS;
}