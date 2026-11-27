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
