# CO1 Assignment Report


---

# Task 1 – Algorithm Design

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

---

# Task 2 – Basic Operation

# Task 2 – Identify the Basic Operation

The input size `n` is the number of student records.

| Strategy | Basic operation counted | Location | Why it dominates |
|---|---|---|---|
| Linear search | Equality comparison `A[i] == x` | Each loop iteration | The algorithm performs at most one key comparison per visited record; count grows directly with records visited. |
| Recursive binary search | Key comparison between `A[mid]` and `x` | Each recursive call | Each comparison decides whether to stop or discard approximately half the remaining interval. |
| Hash table | Stored-key equality comparison during probing | Each occupied slot visited | The hash computation is constant work; collision resolution determines how many stored keys must be checked. |

For hashing, also report **probes** (slots examined) separately from **key comparisons**. An empty slot terminates an unsuccessful lookup without an equality comparison in this implementation. This distinction makes collision behaviour visible.

The operation count is preferable to timing alone because it is less sensitive to processor load, compiler, clock resolution and background processes.

---

# Task 3 – Mathematical Complexity

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

---

# Task 4 – Case Analysis

# Task 4 – Best, Average and Worst Cases

| Algorithm | Best case and condition | Average case and condition | Worst case and condition |
|---|---|---|---|
| Linear | `Θ(1)`: target is first | `Θ(n)`: target position uniformly distributed; expected `(n+1)/2` comparisons | `Θ(n)`: target is last or absent; `n` comparisons |
| Recursive binary | `Θ(1)`: target is first midpoint | `Θ(log n)`: target follows a logarithmic path in a balanced sorted array | `Θ(log n)`: target absent or found at deepest level |
| Hash table | `Θ(1)`: initial bucket directly identifies key, or empty slot for miss | Expected `Θ(1)`: well-distributed hash and bounded load factor | `Θ(n)`: pathological collisions create a long cluster |

**Explanation:** Linear search's work depends on target position because it cannot skip records. Binary search halves the remaining interval regardless of the target's position, so its non-best cases are logarithmic. Hashing normally jumps directly to a bucket, but collisions can require sequential probing. Therefore, expected constant-time hashing is conditional on the hash distribution and load factor; it is not a guaranteed worst-case bound.

For unsuccessful linear search, every record is checked. For unsuccessful binary search, the interval is repeatedly halved until empty. For unsuccessful hash search, probing stops at the first empty slot, but a collision cluster can make the lookup expensive.

---

# Task 5 – Asymptotic Analysis

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

---

# Task 6 – Recurrence Formulation

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

---

# Task 7 – Recurrence Solution

# Task 7 – Solve the Recurrence Relation

Given `T(n) = T(n/2) + c`, `T(1)=d`.

## Iteration / substitution method
```
T(n)       = T(n/2) + c
           = T(n/4) + c + c
           = T(n/8) + 3c
           = T(n/2^k) + kc
```
Stop when `n/2^k = 1`, so `2^k=n` and `k=log₂n`.
Substitute:
`T(n) = T(1) + c log₂n = d + c log₂n = Θ(log n)`.

## Master Theorem
The standard form is `T(n)=aT(n/b)+f(n)`. Here `a=1`, `b=2`, and `f(n)=Θ(1)`.
`n^(log_b a) = n^(log₂1) = n^0 = 1`.
Since `f(n)=Θ(1)=Θ(n^0)`, Master Theorem Case 2 gives:
`T(n)=Θ(log n)`.

Both methods apply because there is one subproblem of half the size and constant non-recursive work. The result means doubling the number of sorted records adds approximately one more recursive level, rather than doubling the search work.

---

# Task 8 – Implementation and Testing

# Task 8 – Implementation and Testing

## Environment
- Language: C11
- Editor: Visual Studio Code
- Compiler: GCC (or compatible C compiler)
- Build command: `gcc -O2 -std=c11 -Wall -Wextra Source_Code/benchmark.c -o benchmark`
- Run: `./benchmark` (Windows PowerShell: `.\benchmark.exe`)

## Dataset
The benchmark creates unique integer registration numbers `202300000` through `202300000+n-1` for each required size: 1,000; 10,000; 100,000; 1,000,000. All algorithms search equivalent keys. Binary search receives the sorted array; linear search uses the same array (linear search does not require sorting); the hash table is built from those keys.

## Test scenarios
- First record (linear best case).
- A successful key at one-third of the array.
- Last record (linear worst successful case).
- An absent key (`999999999`).

The benchmark verifies found/not-found results for all algorithms and records comparison counts. It separately times sorting and hash-table construction. Batch timing repeats each lookup 100 times to reduce timer-resolution noise.

## Important experimental note
The benchmark is a reproducible local experiment, not a claim about production hardware. Record compiler version, CPU, operating system and build flags when submitting. Run more repetitions if timings are near the timer's resolution. Compare operation counts as well as time.

---

# Task 9 – Experimental Performance

# Task 9 – Experimental Performance

Run the benchmark from `Task_8_Implementation_Testing`. It writes `results.csv` containing dataset size, algorithm, scenario, target, found status, comparison/probe count, batch time, per-search time and repetition count.

Preprocessing times (binary sorting and hash construction) are printed to the terminal for each dataset size. Capture this terminal output in `Report/Output_Screenshots/` and record machine/compiler details.

The supplied `Report/Tables_and_Graphs/` contains plots generated from the benchmark run included with this project. Re-run the benchmark on the submission computer and replace `results.csv` and plots if you need results from that machine. Timing is environment-dependent; operation counts are more portable.

---

# Task 10 – Theory vs Experiment

# Task 10 – Compare Theory with Experiment

Use the generated CSV and plots to compare observed comparison counts with theoretical growth:
- Linear search comparisons increase with the position of the target and reach `n` for a missing key.
- Recursive binary search comparisons increase logarithmically; for one million records, a search path is around 20 levels.
- Hash-table probes should remain small on average at load factor no greater than 0.5, but vary with collisions and the chosen key/hash distribution.

Execution times will not match asymptotic counts exactly. Reasons include constant overhead, recursive function-call cost, cache locality, memory allocation, branch prediction, CPU scheduling, compiler version and timer resolution. Binary sorting and hash construction are one-time preprocessing costs and must be discussed separately from lookup latency.

Do not claim that a measured hash-table result proves constant worst-case complexity. The theoretical worst case remains `Θ(n)`.

---

# Task 11 – Final Recommendation

# Task 11 – Final Design Recommendation

For exact registration-number lookups with many queries, recommend the hash-table strategy, provided the measured results confirm low average probe counts and acceptable build time. The benchmark's table capacity is at least twice the number of keys, giving load factor `α <= 0.5`, and uses open addressing with linear probing.

Technical justification:
1. Expected lookup and insertion are `Θ(1)` under a suitable hash distribution and controlled load factor.
2. Building the index is expected `Θ(n)` and is performed once, rather than sorting for every query.
3. Linear search has no preprocessing but worst-case `Θ(n)` per query.
4. Binary search has `Θ(log n)` lookup but needs sorted data; sorting unsorted data costs `Θ(n log n)`.
5. Hashing's limitation is its `Θ(n)` pathological worst case and lack of natural ordered/range traversal.

Final recommendation must be checked against the actual CSV and local machine timings before submission. In a production relational database, use a native index rather than implementing a standalone in-memory table unless the application architecture specifically calls for it.

---

# Task 12 – Design Challenge

# Task 12 – Day-4 Design Challenge (8 Marks)

## A. Impact analysis
The revised workload has one million records, 50,000 searches per hour and only one daily insertion batch. Average request rate is `50,000 / 3,600 = 13.89`, approximately 14 searches/second. Search frequency is now high relative to update frequency, so it is reasonable to spend a one-time cost building an index and optimize repeated lookups. The average rate does not describe bursts or a latency SLA, so production capacity testing is still required.

## B. Evaluate the original design
A hash table remains appropriate for exact-key lookups. Expected lookup is `Θ(1)` at a controlled load factor, and expected construction is `Θ(n)`. One daily insertion batch is inexpensive relative to 50,000 daily? **Correction:** 50,000 requests are specified per hour, so over 24 hours this is 1,200,000 searches/day if sustained. A daily rebuild or batch insertion is therefore amortized over a large number of searches. Binary search remains viable but requires sorted data and `Θ(log n)` per query; linear search is not suitable for this volume.

## C. Adaptation / redesign
**Decision: RETAIN the hash-based strategy, with operational safeguards.**
- Build a hash index at startup or load the daily batch into the existing index.
- Maintain a controlled load factor (e.g. <= 0.5 in this benchmark); resize and rehash when the threshold is exceeded.
- Use a robust hash function and monitor probe lengths/collision distribution.
- Persist the canonical student records in a database; treat the hash table as an in-memory index/cache if appropriate.
- Consider a database-managed B+ tree index if ordered queries, range scans, persistence, crash recovery or multi-node operation are required.

Expected algorithmic cost: expected `Θ(n)` initial build; expected `Θ(1)` exact lookup and insertion; pathological worst-case lookup `Θ(n)`. The daily update pattern makes maintaining an index practical.

## D. Evidence-based defence
At 50,000 requests/hour, the average is 13.89 searches/second. If sustained for 24 hours, that is 1.2 million lookups/day. A one-time `Θ(n)` build for one million keys is amortized across this query volume. By comparison, a worst-case linear scan may inspect one million keys per unsuccessful lookup; binary search requires about 20 midpoint levels but requires sorted data. The included benchmark reports actual comparison counts, probe counts, build time and lookup timing. Insert the machine-specific results from `results.csv` and terminal output here before final submission.

**Limitations:** average request rate does not define peak concurrency, availability, memory budget or response-time target. A real deployment should load-test burst traffic and use a production database index with durability and concurrency controls.
