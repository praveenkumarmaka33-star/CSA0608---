# Task 2 – Merge Sort and Quick Sort

## Merge Sort pseudocode

```text
MERGE_SORT(A)
1. If length(A) <= 1, return A
2. Divide A into left and right halves
3. left = MERGE_SORT(left)
4. right = MERGE_SORT(right)
5. Merge the two sorted halves into one sorted array
6. Return the merged array
```

## Quick Sort pseudocode

```text
QUICK_SORT(A)
1. If length(A) <= 1, return A
2. Select a pivot element
3. Create three groups:
      elements smaller than pivot
      elements equal to pivot
      elements greater than pivot
4. Recursively sort the smaller and greater groups
5. Return sorted-smaller + equal + sorted-greater
```

**Time Complexity:** Merge Sort – O(n log n); Quick Sort – average O(n log n), worst O(n²).
