# Task 7 – Solve the Recurrence Relation

Given `T(n) = T(n/2) + c`, `T(1)=d`.

## Iteration / substitution method
```
T(n)       = T(n/2) + c
           = T(n/4) + c + c
           = T(n/8) + 3c
           = T(n/2^k) + kc
```
Stop when `n/2^k = 1`, so `2^k=n` and `k=log₂n`.
Substitute:
`T(n) = T(1) + c log₂n = d + c log₂n = Θ(log n)`.

## Master Theorem
The standard form is `T(n)=aT(n/b)+f(n)`. Here `a=1`, `b=2`, and `f(n)=Θ(1)`.
`n^(log_b a) = n^(log₂1) = n^0 = 1`.
Since `f(n)=Θ(1)=Θ(n^0)`, Master Theorem Case 2 gives:
`T(n)=Θ(log n)`.

Both methods apply because there is one subproblem of half the size and constant non-recursive work. The result means doubling the number of sorted records adds approximately one more recursive level, rather than doubling the search work.
