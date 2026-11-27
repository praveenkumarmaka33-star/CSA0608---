# Task 6 – Formulate the Recurrence Relation

The recursive algorithm is binary search on a sorted array of `n` registration numbers.

1. **Original input size:** `n` keys in the current interval.
2. **Recursive subproblem:** after checking the midpoint, at most one half remains, of size approximately `n/2`.
3. **Number of recursive calls:** at most one recursive call per non-base invocation (not two calls).
4. **Work outside recursion:** calculate midpoint, compare target with midpoint key, choose a branch. This is constant work `c`.
5. **Base case:** interval is empty (`low > high`), or a one-element interval is checked. We can express the recurrence with `T(1)=d` for a power-of-two simplification.

Therefore:
`T(n) = T(n/2) + c`, for `n > 1`, and `T(1) = d`.

The recurrence follows from the actual code: one midpoint is inspected and only one subinterval is searched. It is not `2T(n/2)` because both halves are never searched.
