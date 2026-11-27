# Task 5 – Closest Pair of Points

**Pseudocode**

```text
CLOSEST_PAIR(P)
1. Sort points by x-coordinate
2. Call SOLVE(P)

SOLVE(P)
1. If number of points <= 3:
      Find and return the minimum distance by checking every pair
2. Divide points into left and right halves
3. Find the closest pair in the left half
4. Find the closest pair in the right half
5. Let d be the smaller of the two distances
6. Create a strip of points whose x-distance from the middle line is less than d
7. Sort the strip by y-coordinate
8. Compare each point with following strip points while their y-distance is less than d
9. Update the best pair and distance when a closer pair is found
10. Return the closest pair and its distance
```

**Time Complexity:** O(n log n) with the divide-and-conquer approach.
