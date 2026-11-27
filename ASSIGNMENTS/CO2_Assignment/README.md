# CSA06 Design and Analysis of Algorithms — Assignment 2 (CO2)

This repository is organised question-wise for Q1–Q7. Implementations use standard C (C11).

## Compile and run
From each `Implementation_Code` folder:
```bash
gcc -std=c11 -O2 main.c -o program -lm
./program
```
On Windows:
```bash
gcc -std=c11 -O2 main.c -o program.exe -lm
program.exe
```

## Folder contents
- `Pseudocode/algorithm.txt`: stepwise algorithm design.
- `Implementation_Code/main.c`: standalone implementation.
- `Output_Screenshots/`: add genuine screenshots from your own execution.

## Evidence and integrity note
Operation counts are the primary evidence. Execution time depends on hardware/compiler and should be measured on your own machine. The report gives analytical expectations and sample test designs; replace/extend observations with the exact outputs from your own compiler run. Do not submit placeholder screenshot files as evidence.

## Question highlights
- Q1 compares Selection, Bubble and Insertion Sort under sorted, reverse and nearly sorted input.
- Q2 investigates successful searches at several positions and unsuccessful searches.
- Q3 counts character comparisons for low-work, repeated-prefix and realistic signature cases.
- Q4 examines every unique point pair; pair count is n(n-1)/2.
- Q5 uses the all-points-on-one-side line test for candidate hull edges.
- Q6 enumerates all 2^n package subsets for the 0/1 knapsack-style airlift problem.
- Q7 diagnoses quadratic pair examination and prototypes a spatial-grid candidate filter. The fixed-neighbour prototype is illustrative, not a universal exact algorithm; the report explains the conditions needed for a guaranteed exact search.

## Viva preparation
Be ready to explain why counts differ from elapsed time, how each test dataset was chosen, and the limitations of the Q5 collinear-point handling and Q7 grid prototype.
