# Task 1 – Maximum and Minimum using Divide and Conquer

**Pseudocode**

```text
MAX_MIN(A, low, high)
1. If low = high:
      Return A[low], A[low]
2. If high = low + 1:
      If A[low] < A[high]:
          Return A[low], A[high]
      Else:
          Return A[high], A[low]
3. mid = floor((low + high) / 2)
4. (min1, max1) = MAX_MIN(A, low, mid)
5. (min2, max2) = MAX_MIN(A, mid + 1, high)
6. minimum = smaller of min1 and min2
7. maximum = larger of max1 and max2
8. Return minimum, maximum

MAIN
1. Read the array A
2. Call MAX_MIN(A, 0, length(A) - 1)
3. Display the minimum and maximum
```

**Time Complexity:** O(n)
