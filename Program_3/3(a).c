#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiply(int *A, int *B, int *C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}

int main() {
    int power, n;

    printf("Enter n (matrix size will be 2^n x 2^n): ");
    scanf("%d", &power);

    n = 1 << power;  

    int *A = (int *)malloc(n * n * sizeof(int));
    int *B = (int *)malloc(n * n * sizeof(int));
    int *C = (int *)malloc(n * n * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < n * n; i++) {
        A[i] = rand() % 10;   
        B[i] = rand() % 10;
    }

    clock_t start = clock();

    for (int i = 0; i < 1000; i++) {
        multiply(A, B, C, n);
    }

    clock_t end = clock();

    double time = ((double)(end - start)) / CLOCKS_PER_SEC / 1000;

    printf("\nFor %d x %d matrix multiplication, time taken = %f seconds\n", n, n, time);

    free(A);
    free(B);
    free(C);

    return 0;
}
