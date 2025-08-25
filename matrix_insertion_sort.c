#include <stdio.h>
#include <stdlib.h>

/*
 * EJERCICIO:
 * Se quiere definir un programa que, dada una matriz cuadrada con valores enteros,
 * devuelva una permutación de los valores de modo que:
 *
 * 1. Cada renglón esté ordenado de menor a mayor.
 * 2. Todos los elementos del segundo renglón (de arriba hacia abajo)
 *    sean mayores que los del primero, los del tercero mayores que los del segundo, etc.
 *
 * Regla importante:
 * - Cuando se ordenan los elementos de un renglón, por cada elemento de dicho renglón,
 *   se mueven también todos los elementos que se encuentran por debajo en la misma columna.
 *
 * INSTRUCCIONES:
 * - Completa la función sort_matrix() que debe modificar la matriz en su lugar.
 * - Puedes escribir funciones auxiliares si lo deseas.
 * - NO cambies la firma de sort_matrix().
 */

void sort_matrix(int **matrix, int *new_matrix, int n) {
    // TODO: Implementa aquí el algoritmo.
    // Necesitarás el método de inserción,
    // pero recuerda aplicar la regla de mover toda la columna.

    //Primera implementacion aplicada:
    /*Esta implementacion sirve pero lo que hace es ordenar renglon a renglon, y no lo solicitado
    que fue ordenar TODA la matriz

    int i, key, j, k;
    for (i = 0; i < n; i++) {
        for(j = 1; j < n; j++){
            key = matrix[i][j];
            k = j - 1;

            while (k >= 0 && matrix[i][k] > key) {
                matrix[i][k + 1] = matrix[i][k];
                k = k - 1;
            }
            matrix[i][k + 1] = key;
        }
    }
    */

    //El numero de elementos de una matriz de tamaño n x n, es la operacion n*n
    int num_elementos = n * n;

    //Copiando los elementos orig en nueva "matriz", ya que ahora es un arreglo 1D
    int i, j, k = 0, key;
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            new_matrix[k] = matrix[i][j];
            k++;
        }
    }

    // Ordenando el arreglo unidimensional
    for (i = 1; i < num_elementos; i++) {
        key = new_matrix[i];
        j = i - 1; 

        while (j >= 0 && new_matrix[j] > key) {
            new_matrix[j + 1] = new_matrix[j];
            j = j - 1;
        }
        new_matrix[j + 1] = key;
    }

    //Reiniciando k para poder volverlo a utilizar
    k = 0;

    //Una vez ordenado, lo copiaremos nuevamente a la matriz original
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = new_matrix[k++];
        }
    }
}

int main() {
    int n = 3;
    // Reserva dinámica de la matriz 1
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Decidi copiar toda la informacion de la matriz original a un arreglo simple con tal de
    // Ordenarlo completamente ahi, para despues meterlo de vuelta a la matriz dada
    // Reserva dinámica del arreglo unidimensional
    int *new_matrix = (int *)malloc(n * n * sizeof(int));

    // Ejemplo de entrada
    int ejemplo[3][3] = {
        {3, 19, -2},
        {1, 5, -21},
        {-54, 200, 4}
    };

    // Copiar ejemplo a la matriz dinámica
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = ejemplo[i][j];
        }
    }

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {   
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Llamada a la función que deben completar
    sort_matrix(matrix, new_matrix, n);
    //sort_matrix(matrix, n);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria de mi primera reserva
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Liberar memoria de mi segunda reserva, que como es un arreglo !d, basta con usar free
    free(new_matrix);

    return 0;
}
