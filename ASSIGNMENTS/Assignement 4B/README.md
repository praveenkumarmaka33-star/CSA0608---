# CO4 Assignment 4B – Algorithm Engineering

**Course:** CSA06 – Design and Analysis of Algorithms  
**Course Outcome:** CO4 – Dynamic Programming and Greedy Strategies  
**Student:** Hassan Saliq

## Structure
```text
CO4_Assignment_4B/
├── Source_Code/
│   ├── Task_1/  # Word Wrap DP
│   ├── Task_2/  # Fractional Greedy and 0/1 Knapsack DP
│   ├── Task_3/  # Dijkstra, Bellman-Ford, Floyd, Warshall
│   ├── Task_4/  # Assembly-line scheduling DP
│   ├── Task_5/  # Kruskal, Prim, Boruvka
│   └── Task_6/  # Held-Karp TSP DP
├── Report/
│   ├── CO4_Assignment_4B_Report.pdf
│   └── Execution_Screenshots/
└── README.md
```

## Compile and run
Use GCC:
```bash
gcc -std=c11 -O2 -Wall -Wextra task_1.c -o program
./program
```
On Windows, run `program.exe`. Each task folder includes source, sample input and captured output.

## Algorithms
1. Word Wrap: suffix DP, reconstructs line breaks; penalty assumed to be square of unused spaces on non-final lines.
2. Knapsack: fractional greedy, 0/1 ratio-greedy heuristic counterexample, and exact 0/1 DP.
3. Routing: Dijkstra, Bellman-Ford negative-edge/cycle tests, Floyd all-pairs distances and Warshall reachability.
4. Assembly line: two-line DP with predecessor reconstruction and per-station stay/transfer comparisons.
5. MST: Kruskal, Prim and Boruvka with edge-selection traces.
6. TSP: Held-Karp subset DP, route reconstruction, state counter and small-instance brute-force validation.

## Important source limitation
The Task 1 penalty equation and maximum line width are missing/blank in the uploaded DOCX extraction and page image. This solution explicitly assumes the common squared-slack penalty `(unused spaces)^2` for non-final lines and takes width as input. Confirm this assumption with the instructor if a separate formula/width was provided.

## Test evidence
The report contains normal, changed-requirement, boundary/failure and adversarial tests, with sample outputs and algorithmic interpretation. PNGs are rendered from the programs' captured stdout; for a requirement demanding screenshots of the actual IDE, run the included programs in your own VS Code terminal and capture with `Win + Shift + S`.
