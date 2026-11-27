# Task 3 – Mathematical Time-Complexity Derivation

Let `n` be the number of records. Count key comparisons as the main basic operation.

## A. Linear search
If the target is at zero-based position `k`, comparisons are `k + 1`. If absent, comparisons are `n`.
- Best: `C_best(n) = 1`.
- Successful average, with each of `n` positions equally likely: `C_avg(n) = (1 + 2 + ... + n)/n = n(n+1)/(2n) = (n+1)/2`.
- Worst: `C_worst(n) = n`.
Thus search is `Θ(1)` best and `Θ(n)` average/worst. No preprocessing is required, so total cost for `q` queries is `Θ(qn)` in the worst case.

## B. Recursive binary search
Assume sorted input and, for a simple derivation, `n` is a power of two. Each call performs constant work (one key comparison plus midpoint/branch work) and recurses into at most one subarray of size `n/2`.
`T(n) = T(n/2) + c`, with `T(1) = d`.
After `k` levels, the subproblem size is `n/2^k`; it reaches 1 when `k = log₂ n`. Therefore `T(n) = d + c log₂ n = Θ(log n)`. Best case is one midpoint comparison, `Θ(1)`; average and worst are `Θ(log n)`.
If unsorted input must be sorted first, preprocessing with comparison sorting costs `Θ(n log n)`. Total for `q` searches is `Θ(n log n + q log n)`. If already sorted, the sorting term is absent.

## C. Hash table search
The benchmark chooses capacity `m >= 2n`, so load factor `α = n/m <= 0.5`. Hash calculation and initial slot computation are constant time.
- Best: target's initial slot is empty for a miss or contains the target for a hit: `Θ(1)`.
- Expected/average: under a suitably distributed hash function and controlled load factor, expected probes and key comparisons are `Θ(1)`.
- Worst: all keys may collide into one probe cluster; up to `n` occupied slots may be examined: `Θ(n)`.
Building the table requires `n` insertions. Under the stated hashing assumptions this is expected `Θ(n)`; pathological collisions can make construction `Θ(n²)`. For `q` queries, expected total cost is `Θ(n + q)` including construction.

## Preprocessing comparison
| Algorithm | Preprocessing on unsorted input | Search cost | Total for q searches |
|---|---:|---:|---:|
| Linear | `Θ(1)` | worst `Θ(n)` | `Θ(qn)` |
| Recursive binary | sorting `Θ(n log n)` | `Θ(log n)` | `Θ(n log n + q log n)` |
| Hash table | build `Θ(n)` expected | `Θ(1)` expected | `Θ(n + q)` expected |

These totals matter: preprocessing should not be hidden when comparing algorithms. The binary sort uses `qsort` in the supplied C benchmark; the C standard does not guarantee a particular asymptotic complexity for every implementation, but common library implementations use an efficient `O(n log n)` sort. The analysis assumes comparison sorting with `Θ(n log n)` time.
