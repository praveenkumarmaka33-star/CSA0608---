# Task 10 – Compare Theory with Experiment

Use the generated CSV and plots to compare observed comparison counts with theoretical growth:
- Linear search comparisons increase with the position of the target and reach `n` for a missing key.
- Recursive binary search comparisons increase logarithmically; for one million records, a search path is around 20 levels.
- Hash-table probes should remain small on average at load factor no greater than 0.5, but vary with collisions and the chosen key/hash distribution.

Execution times will not match asymptotic counts exactly. Reasons include constant overhead, recursive function-call cost, cache locality, memory allocation, branch prediction, CPU scheduling, compiler version and timer resolution. Binary sorting and hash construction are one-time preprocessing costs and must be discussed separately from lookup latency.

Do not claim that a measured hash-table result proves constant worst-case complexity. The theoretical worst case remains `Θ(n)`.
