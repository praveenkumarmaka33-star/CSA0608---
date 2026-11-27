# Task 5 – Asymptotic Analysis

- `O(g(n))` gives an asymptotic upper bound.
- `Ω(g(n))` gives an asymptotic lower bound.
- `Θ(g(n))` gives a tight bound when both upper and lower bounds have the same growth.

| Algorithm | Best | Average/expected | Worst |
|---|---|---|---|
| Linear search | `Θ(1)` | `Θ(n)` | `Θ(n)` |
| Recursive binary search | `Θ(1)` | `Θ(log n)` | `Θ(log n)` |
| Hash table | `Θ(1)` | expected `Θ(1)` | `Θ(n)` |

For `n = 1,000,000`, linear worst-case search can inspect one million keys. Binary search needs about `log₂(1,000,000) ≈ 19.93`, i.e. roughly 20 levels. A hash lookup is expected to inspect a small number of slots at the benchmark's load factor, although a pathological collision pattern can still cause linear work.

Asymptotic notation describes growth, not exact milliseconds. Constant factors, memory locality, hashing overhead, sorting/building time, compiler optimizations and hardware influence measured time.
