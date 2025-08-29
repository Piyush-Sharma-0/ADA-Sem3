def multiplication(matrix1, matrix2):
    if len(matrix1[0]) != len(matrix2):
        print("Invalid matrices")
        return -1

    row1 = len(matrix1)
    column1 = len(matrix1[0])
    row2 = len(matrix2)
    column2 = len(matrix2[0])

    result = [[0 for _ in range(column2)] for _ in range(row1)]

    for i in range(row1):
        for j in range(column2):
            total = 0
            for k in range(column1):
                total += matrix1[i][k] * matrix2[k][j]
            result[i][j] = total
    return result


matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
matrix2 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

result = multiplication(matrix1, matrix2)
print(result)
