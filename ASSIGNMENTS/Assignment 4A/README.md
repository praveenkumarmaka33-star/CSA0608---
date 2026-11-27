# CO4 Assignment 4A – CSA06 Design and Analysis of Algorithms

**Student:** Hassan Saliq  
**Assignment:** Assignment 4 – CO4, Part I  
**Course Outcome:** Solve optimization problems using Dynamic Programming and Greedy strategies.

## Repository structure

```text
CO4_Assignment_4A/
├── Source_Code/
│   ├── Task_1/
│   ├── Task_2/
│   ├── Task_3/
│   ├── Task_4/
│   ├── Task_5/
│   └── Task_6/
├── Report/
│   ├── CO4_Assignment_4A_Report.pdf
│   └── Execution_Screenshots/
└── README.md
```

## Tasks implemented

1. **Fractional Knapsack** – greedy selection by descending value/weight ratio.
2. **Job Sequencing with Deadlines** – descending profit order and latest available feasible slot.
3. **0/1 Knapsack** – dynamic programming with item reconstruction.
4. **Word Break** – dynamic programming; a prefix is accepted only when the earlier prefix is segmentable.
5. **Shortest Paths** – Dijkstra, Bellman-Ford and Floyd-Warshall on the supplied directed graph.
6. **Energy-Aware Job Scheduling** – weighted interval scheduling using dynamic programming and reconstruction.

## Compile and run

Each task is a standalone C program. Example:

```bash
cd Source_Code/Task_1
gcc -std=c11 -Wall -Wextra task_1.c -o program
./program
```

On Windows, run `program.exe` after compilation. Use the sample input values in the assignment or enter your own values when prompted. Each task folder includes a `sample_output.txt` file.

## Execution evidence

The `Report/Execution_Screenshots/` folder contains captured outputs from successful local executions of all six programs, in PNG and text formats.

## Important note about the assignment brief

The uploaded question paper says the assignment is intended to assess language-independent pseudocode and explicitly says a compiler/programming language is not required. The initial submission statement separately asks for implementations and execution screenshots. This repository includes both: the pseudocode/design report and a separate C implementation supplement. Confirm with the instructor which instruction takes precedence before final submission.

## Test cases used

- Task 1: 3 packages, capacity 50.
- Task 2: A(2,80), B(1,35), C(2,60), D(3,40), E(1,25).
- Task 3: P(2,12), Q(3,20), R(4,25), S(5,30), capacity 7.
- Task 4: `catdog`, dictionary `{cat, dog}`.
- Task 5: Directed graph supplied in the assignment.
- Task 6: The eight jobs J1–J8 supplied in the assignment.

