# Task 2 – Identify the Basic Operation

The input size `n` is the number of student records.

| Strategy | Basic operation counted | Location | Why it dominates |
|---|---|---|---|
| Linear search | Equality comparison `A[i] == x` | Each loop iteration | The algorithm performs at most one key comparison per visited record; count grows directly with records visited. |
| Recursive binary search | Key comparison between `A[mid]` and `x` | Each recursive call | Each comparison decides whether to stop or discard approximately half the remaining interval. |
| Hash table | Stored-key equality comparison during probing | Each occupied slot visited | The hash computation is constant work; collision resolution determines how many stored keys must be checked. |

For hashing, also report **probes** (slots examined) separately from **key comparisons**. An empty slot terminates an unsuccessful lookup without an equality comparison in this implementation. This distinction makes collision behaviour visible.

The operation count is preferable to timing alone because it is less sensitive to processor load, compiler, clock resolution and background processes.
