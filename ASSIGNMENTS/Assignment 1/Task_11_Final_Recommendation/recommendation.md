# Task 11 – Final Design Recommendation

For exact registration-number lookups with many queries, recommend the hash-table strategy, provided the measured results confirm low average probe counts and acceptable build time. The benchmark's table capacity is at least twice the number of keys, giving load factor `α <= 0.5`, and uses open addressing with linear probing.

Technical justification:
1. Expected lookup and insertion are `Θ(1)` under a suitable hash distribution and controlled load factor.
2. Building the index is expected `Θ(n)` and is performed once, rather than sorting for every query.
3. Linear search has no preprocessing but worst-case `Θ(n)` per query.
4. Binary search has `Θ(log n)` lookup but needs sorted data; sorting unsorted data costs `Θ(n log n)`.
5. Hashing's limitation is its `Θ(n)` pathological worst case and lack of natural ordered/range traversal.

Final recommendation must be checked against the actual CSV and local machine timings before submission. In a production relational database, use a native index rather than implementing a standalone in-memory table unless the application architecture specifically calls for it.
