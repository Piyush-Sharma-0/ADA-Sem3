#include <stdio.h>
#include <stdlib.h>

void multiply(int *A, int *B, int *C, int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Invalid matrices: columns of A != rows of B\n");
        return;
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            C[i * col2 + j] = 0;
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                C[i * col2 + j] += A[i * col1 + k] * B[k * col2 + j];
            }
        }
    }
}

int main() {
    int row1, col1, row2, col2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Invalid matrices: columns of A != rows of B\n");
        return 1;
    }

    int *A = (int *)malloc(row1 * col1 * sizeof(int));
    int *B = (int *)malloc(row2 * col2 * sizeof(int));
    int *C = (int *)malloc(row1 * col2 * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &A[i * col1 + j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &B[i * col2 + j]);
        }
    }

    multiply(A, B, C, row1, col1, row2, col2);

    printf("Result Matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", C[i * col2 + j]);
        }
        printf("\n");
    }

    
    free(A);
    free(B);
    free(C);

    return 0;
}
