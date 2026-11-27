# Task 1 – Design the Algorithm

## Problem definition
Given `n` student records identified by unique integer registration numbers and a target registration number `x`, determine whether `x` exists and return its record position. The three strategies are deliberately distinct: sequential scan, divide-and-conquer binary search, and hash-based lookup.

## 1. Linear Search (iterative, sequential strategy)
**Idea:** Inspect records from the first position onward and stop when the target is found or the array ends. It works on unsorted input and requires no preprocessing.

**Pseudocode**
```text
LINEAR-SEARCH(A, n, x)
    for i = 0 to n - 1
        if A[i].registration_no == x
            return i
    return NOT_FOUND
```
**Justification:** It is the baseline strategy, handles unsorted records, is simple, and has no index-building or sorting cost. It can be competitive for very small datasets or searches likely to match near the beginning.

## 2. Recursive Binary Search (divide-and-conquer strategy)
**Idea:** The input must be sorted by registration number. Compare the target with the middle key and recursively continue in only the left or right half.

**Pseudocode**
```text
RECURSIVE-BINARY-SEARCH(A, low, high, x)
    if low > high
        return NOT_FOUND
    mid = low + floor((high - low) / 2)
    if A[mid].registration_no == x
        return mid
    if x < A[mid].registration_no
        return RECURSIVE-BINARY-SEARCH(A, low, mid - 1, x)
    return RECURSIVE-BINARY-SEARCH(A, mid + 1, high, x)
```
**Preprocessing:** If records are initially unsorted, sort once using an `O(n log n)` comparison sort. If the database is already maintained in sorted order, this one-time cost is not incurred for each query.

**Justification:** It is a classic recursive divide-and-conquer method and reduces the remaining search interval by half on each call. It gives a clear recurrence for Tasks 6–7.

## 3. Hash Table Search (hashing strategy)
**Idea:** Apply a hash function to the registration number to choose a table slot. The implementation uses open addressing with linear probing. If a slot is occupied by a different key, inspect the next slot until the key is found or an empty slot proves absence.

**Pseudocode**
```text
HASH-SEARCH(H, capacity, x)
    i = HASH(x) mod capacity
    probes = 0
    while H[i] is occupied and probes < capacity
        if H[i].key == x
            return i
        i = (i + 1) mod capacity
        probes = probes + 1
    return NOT_FOUND
```
**Preprocessing:** Build the table by inserting all `n` keys. With a suitable hash function, controlled load factor and expected constant-time insertion, construction is expected `O(n)`. The benchmark uses capacity at least `2n`, so load factor is at most 0.5.

**Justification:** Registration-number retrieval is an exact-match workload. Hashing provides expected constant-time lookup and is a strong candidate for the high-query, low-update design challenge.

## Flow descriptions
- Linear: Start → inspect next record → match? yes: return found; no: more records? yes: repeat; no: return not found.
- Recursive binary: Start → interval empty? yes: not found; otherwise inspect midpoint → match? yes: found; target smaller? recurse left; otherwise recurse right.
- Hash: Start → compute slot → slot empty? yes: not found; key matches? yes: found; otherwise probe next slot and repeat.

## Assumptions
Registration numbers are unique integers. Binary search receives sorted keys. Hash table capacity is a power of two and at least twice the number of records in the benchmark. The measured hash worst case is not a mathematical worst-case construction; theoretical worst case remains linear under pathological collisions.
