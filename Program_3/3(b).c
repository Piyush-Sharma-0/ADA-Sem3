#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_matrix(int* A, int* B, int* C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i*n + j] = A[i*n + j] + B[i*n + j];
}

void split_matrix(int* M, int n, int** A11, int** A12, int** A21, int** A22) {
    int mid = n / 2;
    *A11 = (int*)malloc(mid * mid * sizeof(int));
    *A12 = (int*)malloc(mid * mid * sizeof(int));
    *A21 = (int*)malloc(mid * mid * sizeof(int));
    *A22 = (int*)malloc(mid * mid * sizeof(int));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            (*A11)[i*mid + j] = M[i*n + j];
            (*A12)[i*mid + j] = M[i*n + j + mid];
            (*A21)[i*mid + j] = M[(i+mid)*n + j];
            (*A22)[i*mid + j] = M[(i+mid)*n + j + mid];
        }
    }
}

int* merge_matrix(int* A11, int* A12, int* A21, int* A22, int mid) {
    int n = mid * 2;
    int* C = (int*)malloc(n * n * sizeof(int));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i*n + j] = A11[i*mid + j];
            C[i*n + j + mid] = A12[i*mid + j];
            C[(i+mid)*n + j] = A21[i*mid + j];
            C[(i+mid)*n + j + mid] = A22[i*mid + j];
        }
    }
    return C;
}

int* multiplication(int* A, int* B, int n) {
    if (n == 1) {
        int* C = (int*)malloc(sizeof(int));
        C[0] = A[0] * B[0];
        return C;
    }

    int mid = n / 2;

    int *A11, *A12, *A21, *A22;
    int *B11, *B12, *B21, *B22;
    split_matrix(A, n, &A11, &A12, &A21, &A22);
    split_matrix(B, n, &B11, &B12, &B21, &B22);

    int *C11, *C12, *C21, *C22;
    int* temp1 = (int*)malloc(mid * mid * sizeof(int));

    int* M1 = multiplication(A11, B11, mid);
    int* M2 = multiplication(A12, B21, mid);
    add_matrix(M1, M2, temp1, mid);
    C11 = (int*)malloc(mid * mid * sizeof(int));
    for (int i = 0; i < mid*mid; i++) C11[i] = temp1[i];
    free(M1); free(M2);

    M1 = multiplication(A11, B12, mid);
    M2 = multiplication(A12, B22, mid);
    add_matrix(M1, M2, temp1, mid);
    C12 = (int*)malloc(mid * mid * sizeof(int));
    for (int i = 0; i < mid*mid; i++) C12[i] = temp1[i];
    free(M1); free(M2);

    M1 = multiplication(A21, B11, mid);
    M2 = multiplication(A22, B21, mid);
    add_matrix(M1, M2, temp1, mid);
    C21 = (int*)malloc(mid * mid * sizeof(int));
    for (int i = 0; i < mid*mid; i++) C21[i] = temp1[i];
    free(M1); free(M2);

    M1 = multiplication(A21, B12, mid);
    M2 = multiplication(A22, B22, mid);
    add_matrix(M1, M2, temp1, mid);
    C22 = (int*)malloc(mid * mid * sizeof(int));
    for (int i = 0; i < mid*mid; i++) C22[i] = temp1[i];
    free(M1); free(M2);

    free(temp1);
    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);

    int* C = merge_matrix(C11, C12, C21, C22, mid);

    free(C11); free(C12); free(C21); free(C22);

    return C;
}

int main() {
    int power, n;
    printf("Enter n (matrix size will be 2^n x 2^n): ");
    scanf("%d", &power);

    n = 1 << power; 

    int* A = (int*)malloc(n * n * sizeof(int));
    int* B = (int*)malloc(n * n * sizeof(int));

    if (A == NULL || B == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < n*n; i++) {
        A[i] = rand() % 10; 
        B[i] = rand() % 10;
    }

    clock_t start = clock();
    //for (int i = 0; i < 10; i++) {  // run multiple times for averaging
        int* temp = multiplication(A, B, n);
        free(temp);
    //}
    clock_t end = clock();

    double time = ((double)(end - start)) / CLOCKS_PER_SEC / 1;

    printf("\nFor %dx%d matrix multiplication, time taken = %f seconds\n", n, n, time);

    free(A);
    free(B);
    return 0;
}
