# CO5 Assignment 5 – Search, Complexity and Approximation Engineering

**Course:** CSA06 – Design and Analysis of Algorithms  
**CO:** CO5  
**Student:** Hassan Saliq  
**Register Number:** 192421322  
**Department:** B.Tech IT

## Folder structure
- `Source_Code/Task_B1_Graph_Colouring/` – instrumented graph colouring, test inputs and outputs
- `Source_Code/Task_B2_Adversarial_Search/` – same-size adversarial graph comparison
- `Source_Code/Task_B3_Exact_vs_Approximation/` – exact and greedy set cover
- `Source_Code/Task_B4_Bin_Packing/` – First-Fit Decreasing bin packing
- `Report/CO5_Assignment_5_Report.pdf` – consolidated Part A and Part B report

## Compile and run
Use GCC:
```bash
gcc -std=c11 -O2 Source_Code/Task_B1_Graph_Colouring/graph_colouring.c -o graph_colouring
./graph_colouring < Source_Code/Task_B1_Graph_Colouring/Test_Inputs/triangle_3col.txt

gcc -std=c11 -O2 Source_Code/Task_B2_Adversarial_Search/adversarial_search.c -o adversarial_search
./adversarial_search

gcc -std=c11 -O2 Source_Code/Task_B3_Exact_vs_Approximation/set_cover.c -o set_cover
./set_cover

gcc -std=c11 -O2 Source_Code/Task_B4_Bin_Packing/bin_packing.c -o bin_packing
echo "8 10 7 6 5 5 4 4 3 2" | ./bin_packing
```

## Notes
- Part A pseudocode is language-independent, as required by the assignment.
- Part B implementations are in C.
- Execution output files are included as reproducible evidence. Run on your own system and capture terminal screenshots if your instructor specifically requires screenshots.
- B1 uses input-order and descending-degree vertex ordering. B2 compares an easy path graph with a non-3-colourable graph containing a K4. B3 includes a greedy counterexample. B4 uses First-Fit Decreasing.
