# CO1 Assignment – Student Registration Number Search

**Course:** CSA06 Design and Analysis of Algorithms  
**Assignment:** Assignment 1 – CO1  
**Language:** C (C11)  
**Editor:** Visual Studio Code

## Objective
Design, analyse, implement and compare three distinct strategies for locating student registration numbers: iterative Linear Search, recursive Binary Search, and Hash Table Search using open addressing with linear probing.

## Algorithms
1. **Linear Search:** sequential scan; works on unsorted data; `Θ(n)` average/worst.
2. **Recursive Binary Search:** divide and conquer; requires sorted data; `Θ(log n)` search.
3. **Hash Table Search:** hashing with linear probing; expected `Θ(1)` lookup at controlled load factor; worst `Θ(n)`.

## Dataset sizes
The official assignment specifies 1,000, 10,000, 100,000 and 1,000,000 records.

## Compile and run
Install GCC and ensure `gcc` is on PATH.

```bash
gcc -O2 -std=c11 -Wall -Wextra Task_8_Implementation_Testing/Source_Code/benchmark.c -o benchmark
./benchmark
```

On Windows PowerShell:
```powershell
gcc -O2 -std=c11 -Wall -Wextra .\Task_8_Implementation_Testing\Source_Code\benchmark.c -o benchmark.exe
.\benchmark.exe
```

The program creates `results.csv` in the current working directory and prints sorting and hash-table build times. It tests first, one-third, last and absent keys, and records comparisons/probes and batch timing.

## Experimental notes
- The binary search array is sorted using `qsort`; sorting time is measured separately.
- The hash table is built once per dataset, with capacity at least twice the number of records.
- Lookup timing repeats each target 100 times.
- Timing varies by CPU, compiler, operating system and background load. Re-run locally before final submission.
- Hash-table average complexity assumes a suitable hash distribution and controlled load factor; worst case remains linear.

## Repository structure
See the task folders. Each task has a dedicated Markdown explanation. `Report/` contains benchmark output, measured graphs, analysis and documentation placeholders for screenshots.

## Before submission
1. Run the benchmark on your own computer.
2. Save screenshots of source code and terminal output in the corresponding `Report/` folders.
3. Update Task 9–11 and Task 12 with your own measured values and machine details.
4. Verify all test cases and upload the folder to your GitHub repository.
