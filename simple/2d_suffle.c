/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

// Function to print a matrix of any size
void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d  ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

// Function to modify a matrix of any size
void modifyMatrix(int *matrix, int rows, int cols) {
    int out[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out[i][j] = *(matrix + j * cols + i);
        }
    }
    memcpy(matrix, out, rows * cols * sizeof(int));
}

int main() {
    int rows = 4, cols = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original matrix:\n");
    printMatrix((int *)matrix, rows, cols);

    modifyMatrix((int *)matrix, rows, cols);

    printf("\nModified matrix:\n");
    printMatrix((int *)matrix, rows, cols);

    return 0;
}