# Task 3 – Karatsuba Multiplication

**Pseudocode**

```text
KARATSUBA(x, y)
1. If x or y is a single-digit number:
      Return x * y
2. n = maximum number of digits in x and y
3. m = floor(n / 2)
4. Split:
      x = a * 10^m + b
      y = c * 10^m + d
5. z0 = KARATSUBA(b, d)
6. z2 = KARATSUBA(a, c)
7. z1 = KARATSUBA(a + b, c + d) - z2 - z0
8. Return z2 * 10^(2m) + z1 * 10^m + z0

MAIN
1. Read two integers x and y
2. Display KARATSUBA(x, y)
```

**Time Complexity:** O(n^log₂3), approximately O(n^1.585).
