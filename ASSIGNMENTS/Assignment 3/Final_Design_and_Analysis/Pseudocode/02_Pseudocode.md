# Task 7 – Maximum Subarray using Divide and Conquer

**Pseudocode**

```text
MAX_SUBARRAY(A, low, high)
1. If low = high:
      Return A[low]
2. mid = floor((low + high) / 2)
3. left_sum = MAX_SUBARRAY(A, low, mid)
4. right_sum = MAX_SUBARRAY(A, mid + 1, high)
5. Find the maximum sum of a subarray crossing the midpoint:
      Scan left from mid and record the largest left sum
      Scan right from mid + 1 and record the largest right sum
      crossing_sum = largest_left_sum + largest_right_sum
6. Return the maximum of left_sum, right_sum and crossing_sum

MAIN
1. Read array A
2. Call MAX_SUBARRAY(A, 0, length(A) - 1)
3. Display the maximum subarray sum
```

**Time Complexity:** O(n log n).
