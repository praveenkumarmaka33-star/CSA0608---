# Measured benchmark results

**Environment note:** These are measurements from the execution environment used to build this project. Re-run on your own VS Code/GCC computer and replace them if your instructor expects local-machine results.

## Unsuccessful lookup: comparisons and time per search

|       n | algorithm       |   comparisons |   ms_per_search |
|--------:|:----------------|--------------:|----------------:|
|    1000 | Linear          |          1000 |         0.00028 |
|    1000 | RecursiveBinary |            10 |         1e-05   |
|    1000 | HashTable       |             0 |         1e-05   |
|   10000 | Linear          |         10000 |         0.00272 |
|   10000 | RecursiveBinary |            14 |         2e-05   |
|   10000 | HashTable       |             1 |         0       |
|  100000 | Linear          |        100000 |         0.03425 |
|  100000 | RecursiveBinary |            17 |         2e-05   |
|  100000 | HashTable       |             1 |         1e-05   |
| 1000000 | Linear          |       1000000 |         0.33958 |
| 1000000 | RecursiveBinary |            20 |         2e-05   |
| 1000000 | HashTable       |             0 |         1e-05   |

## Preprocessing time

|          n |   binary_sort_ms |   hash_build_ms |
|-----------:|-----------------:|----------------:|
|   1000     |            0.066 |           0.084 |
|  10000     |            0.248 |           0.89  |
| 100000     |            3.15  |           4.339 |
|      1e+06 |           30.625 |          47.399 |
