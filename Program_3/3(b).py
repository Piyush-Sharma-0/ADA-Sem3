def add_matrix(A, B):
    n = len(A)
    C = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] + B[i][j]
    return C

def sub_matrix(A, B):
    n = len(A)
    C = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] - B[i][j]
    return C

def split_matrix(M):
    n = len(M)
    mid = n // 2
    A11 = [row[:mid] for row in M[:mid]]
    A12 = [row[mid:] for row in M[:mid]]
    A21 = [row[:mid] for row in M[mid:]]
    A22 = [row[mid:] for row in M[mid:]]
    return A11, A12, A21, A22

def merge_matrix(A11, A12, A21, A22):
    n = len(A11) * 2
    C = [[0]*n for _ in range(n)]
    mid = n // 2
    for i in range(mid):
        C[i][:mid] = A11[i]
        C[i][mid:] = A12[i]
    for i in range(mid):
        C[i+mid][:mid] = A21[i]
        C[i+mid][mid:] = A22[i]
    return C

def multiplication(A, B):
    n = len(A)
    if n == 1:   
        return [[A[0][0] * B[0][0]]]

    A11, A12, A21, A22 = split_matrix(A)
    B11, B12, B21, B22 = split_matrix(B)

    C11 = add_matrix(multiplication(A11, B11), multiplication(A12, B21))
    C12 = add_matrix(multiplication(A11, B12), multiplication(A12, B22))
    C21 = add_matrix(multiplication(A21, B11), multiplication(A22, B21))
    C22 = add_matrix(multiplication(A21, B12), multiplication(A22, B22))

    return merge_matrix(C11, C12, C21, C22)


A = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
B = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]

C = multiplication(A,B)
print(C)
