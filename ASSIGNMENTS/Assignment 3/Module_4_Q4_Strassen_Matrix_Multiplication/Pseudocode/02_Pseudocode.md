# Task 4 – Strassen Matrix Multiplication

**Pseudocode**

```text
STRASSEN(A, B)
1. If matrix size is 1:
      Return the product of the two elements
2. Divide A and B into four equal submatrices:
      A11, A12, A21, A22
      B11, B12, B21, B22
3. Calculate:
      M1 = STRASSEN(A11 + A22, B11 + B22)
      M2 = STRASSEN(A21 + A22, B11)
      M3 = STRASSEN(A11, B12 - B22)
      M4 = STRASSEN(A22, B21 - B11)
      M5 = STRASSEN(A11 + A12, B22)
      M6 = STRASSEN(A21 - A11, B11 + B12)
      M7 = STRASSEN(A12 - A22, B21 + B22)
4. Calculate:
      C11 = M1 + M4 - M5 + M7
      C12 = M3 + M5
      C21 = M2 + M4
      C22 = M1 - M2 + M3 + M6
5. Combine C11, C12, C21 and C22
6. Return the result matrix
```

**Note:** This implementation accepts square matrices with an order that is a power of 2.

**Time Complexity:** O(n^log₂7), approximately O(n^2.807).
