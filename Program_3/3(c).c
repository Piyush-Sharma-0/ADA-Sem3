#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_matrix(int* A, int* B, int* C, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i*n + j] = A[i*n + j] + B[i*n + j];
}

void sub_matrix(int* A, int* B, int* C, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i*n + j] = A[i*n + j] - B[i*n + j];
}

void split_matrix(int* M, int n, int** A11, int** A12, int** A21, int** A22) {
    int mid = n/2;
    *A11 = (int*)malloc(mid*mid*sizeof(int));
    *A12 = (int*)malloc(mid*mid*sizeof(int));
    *A21 = (int*)malloc(mid*mid*sizeof(int));
    *A22 = (int*)malloc(mid*mid*sizeof(int));

    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            (*A11)[i*mid+j] = M[i*n + j];
            (*A12)[i*mid+j] = M[i*n + j + mid];
            (*A21)[i*mid+j] = M[(i+mid)*n + j];
            (*A22)[i*mid+j] = M[(i+mid)*n + j + mid];
        }
    }
}

int* merge_matrix(int* A11, int* A12, int* A21, int* A22, int mid) {
    int n = mid*2;
    int* C = (int*)malloc(n*n*sizeof(int));
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            C[i*n + j] = A11[i*mid+j];
            C[i*n + j + mid] = A12[i*mid+j];
            C[(i+mid)*n + j] = A21[i*mid+j];
            C[(i+mid)*n + j + mid] = A22[i*mid+j];
        }
    }
    return C;
}

int* multiplication(int* A, int* B, int n) {
    if(n == 1){
        int* C = (int*)malloc(sizeof(int));
        C[0] = A[0]*B[0];
        return C;
    }

    int mid = n/2;

    int *A11,*A12,*A21,*A22;
    int *B11,*B12,*B21,*B22;
    split_matrix(A,n,&A11,&A12,&A21,&A22);
    split_matrix(B,n,&B11,&B12,&B21,&B22);

    int* temp1=(int*)malloc(mid*mid*sizeof(int));
    int* temp2=(int*)malloc(mid*mid*sizeof(int));
    int* temp3=(int*)malloc(mid*mid*sizeof(int));

    add_matrix(A11,A22,temp1,mid);
    add_matrix(B11,B22,temp2,mid);
    int* P = multiplication(temp1,temp2,mid);

    add_matrix(A21,A22,temp1,mid);
    int* Q = multiplication(temp1,B11,mid);

    sub_matrix(B12,B22,temp3,mid);
    int* R = multiplication(A11,temp3,mid);

    sub_matrix(B21,B11,temp3,mid);
    int* S = multiplication(A22,temp3,mid);

    add_matrix(A11,A12,temp1,mid);
    int* T = multiplication(temp1,B22,mid);

    sub_matrix(A21,A11,temp3,mid);
    add_matrix(B11,B12,temp2,mid);
    int* U = multiplication(temp3,temp2,mid);

    sub_matrix(A12,A22,temp3,mid);
    add_matrix(B21,B22,temp2,mid);
    int* V = multiplication(temp3,temp2,mid);

    int* C11=(int*)malloc(mid*mid*sizeof(int));
    int* C12=(int*)malloc(mid*mid*sizeof(int));
    int* C21=(int*)malloc(mid*mid*sizeof(int));
    int* C22=(int*)malloc(mid*mid*sizeof(int));

    add_matrix(P,S,temp1,mid);
    sub_matrix(temp1,T,temp3,mid);
    add_matrix(temp3,V,C11,mid);

    add_matrix(R,T,C12,mid);
    add_matrix(Q,S,C21,mid);

    add_matrix(P,R,temp1,mid);
    sub_matrix(temp1,Q,temp3,mid);
    add_matrix(temp3,U,C22,mid);

    free(temp1); free(temp2); free(temp3);
    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(P); free(Q); free(R); free(S); free(T); free(U); free(V);

    int* C = merge_matrix(C11,C12,C21,C22,mid);

    free(C11); free(C12); free(C21); free(C22);

    return C;
}

int main() {
    int power, n;
    printf("Enter n (matrix size will be 2^n x 2^n): ");
    scanf("%d",&power);

    n = 1 << power; 

    int* A=(int*)malloc(n*n*sizeof(int));
    int* B=(int*)malloc(n*n*sizeof(int));

    if(A==NULL || B==NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    for(int i=0;i<n*n;i++){
        A[i] = rand()%10;  
        B[i] = rand()%10;
    }

    clock_t start=clock();
    for(int i=0;i<10;i++){
        int* temp=multiplication(A,B,n);
        free(temp);
    }
    clock_t end=clock();

    double time=((double)(end-start))/CLOCKS_PER_SEC/10;
    printf("\nFor %dx%d Strassen multiplication, time taken = %f seconds\n",n,n,time);

    free(A); free(B);
    return 0;
}
