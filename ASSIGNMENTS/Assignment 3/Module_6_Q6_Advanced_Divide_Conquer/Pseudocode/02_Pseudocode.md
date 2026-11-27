# Task 6 – Advanced Divide and Conquer

## Task 6A: Median of Medians

```text
SELECT(A, k)
1. If A contains at most 5 elements:
      Sort A and return its k-th smallest element
2. Divide A into groups of at most 5 elements
3. Find the median of each group
4. Recursively find the median of the medians; use it as pivot
5. Partition A into:
      L = elements smaller than pivot
      E = elements equal to pivot
      G = elements greater than pivot
6. If k <= size(L), return SELECT(L, k)
7. If k <= size(L) + size(E), return pivot
8. Otherwise return SELECT(G, k - size(L) - size(E))
```

## Task 6B: Meet in the Middle for Subset Sum

```text
MEET_IN_THE_MIDDLE(A, target)
1. Divide A into left and right halves
2. Generate all subset sums of the left half
3. Generate all subset sums of the right half
4. Store right-half sums in a set
5. For each sum s in left-half sums:
      If target - s exists in the right-half set:
          Return TRUE
6. Return FALSE
```

**Time Complexity:**
- Median of Medians selection: O(n) worst case.
- Meet in the Middle subset sum: O(2^(n/2)) time and space.
