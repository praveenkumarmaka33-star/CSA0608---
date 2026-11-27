# TASK 4: Strassen Matrix Multiplication
# Accepts square matrices whose order is a power of 2.

def add(A, B):
    n = len(A)
    return [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]


def subtract(A, B):
    n = len(A)
    return [[A[i][j] - B[i][j] for j in range(n)] for i in range(n)]


def strassen(A, B):
    n = len(A)
    if n == 1:
        return [[A[0][0] * B[0][0]]]

    mid = n // 2
    A11 = [row[:mid] for row in A[:mid]]
    A12 = [row[mid:] for row in A[:mid]]
    A21 = [row[:mid] for row in A[mid:]]
    A22 = [row[mid:] for row in A[mid:]]
    B11 = [row[:mid] for row in B[:mid]]
    B12 = [row[mid:] for row in B[:mid]]
    B21 = [row[:mid] for row in B[mid:]]
    B22 = [row[mid:] for row in B[mid:]]

    M1 = strassen(add(A11, A22), add(B11, B22))
    M2 = strassen(add(A21, A22), B11)
    M3 = strassen(A11, subtract(B12, B22))
    M4 = strassen(A22, subtract(B21, B11))
    M5 = strassen(add(A11, A12), B22)
    M6 = strassen(subtract(A21, A11), add(B11, B12))
    M7 = strassen(subtract(A12, A22), add(B21, B22))

    C11 = add(subtract(add(M1, M4), M5), M7)
    C12 = add(M3, M5)
    C21 = add(M2, M4)
    C22 = add(subtract(add(M1, M3), M2), M6)

    top = [C11[i] + C12[i] for i in range(mid)]
    bottom = [C21[i] + C22[i] for i in range(mid)]
    return top + bottom


def main():
    n = int(input("Enter matrix order (power of 2, e.g. 2 or 4): "))
    if n < 1 or (n & (n - 1)) != 0:
        print("Matrix order must be a positive power of 2.")
        return

    print("Enter matrix A row by row:")
    A = [list(map(int, input().split())) for _ in range(n)]
    print("Enter matrix B row by row:")
    B = [list(map(int, input().split())) for _ in range(n)]

    if any(len(row) != n for row in A + B):
        print("Each row must contain exactly", n, "integers.")
        return

    C = strassen(A, B)
    print("Product matrix:")
    for row in C:
        print(*row)


if __name__ == "__main__":
    main()
