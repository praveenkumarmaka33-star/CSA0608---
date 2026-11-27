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
