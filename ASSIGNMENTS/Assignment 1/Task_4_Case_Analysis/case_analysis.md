# Task 4 – Best, Average and Worst Cases

| Algorithm | Best case and condition | Average case and condition | Worst case and condition |
|---|---|---|---|
| Linear | `Θ(1)`: target is first | `Θ(n)`: target position uniformly distributed; expected `(n+1)/2` comparisons | `Θ(n)`: target is last or absent; `n` comparisons |
| Recursive binary | `Θ(1)`: target is first midpoint | `Θ(log n)`: target follows a logarithmic path in a balanced sorted array | `Θ(log n)`: target absent or found at deepest level |
| Hash table | `Θ(1)`: initial bucket directly identifies key, or empty slot for miss | Expected `Θ(1)`: well-distributed hash and bounded load factor | `Θ(n)`: pathological collisions create a long cluster |

**Explanation:** Linear search's work depends on target position because it cannot skip records. Binary search halves the remaining interval regardless of the target's position, so its non-best cases are logarithmic. Hashing normally jumps directly to a bucket, but collisions can require sequential probing. Therefore, expected constant-time hashing is conditional on the hash distribution and load factor; it is not a guaranteed worst-case bound.

For unsuccessful linear search, every record is checked. For unsuccessful binary search, the interval is repeatedly halved until empty. For unsuccessful hash search, probing stops at the first empty slot, but a collision cluster can make the lookup expensive.
