#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[20];
    int deadline, profit;
} Job;

int compare_profit(const void *a, const void *b) {
    const Job *x = (const Job *)a;
    const Job *y = (const Job *)b;
    return y->profit - x->profit;
}

int main(void) {
    int n, maxDeadline = 0, totalProfit = 0;
    Job jobs[100];
    char schedule[101][20] = {{0}};

    printf("Enter number of jobs: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter job ID, deadline and profit: ");
        scanf("%19s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline < 1 || jobs[i].profit < 0) return 1;
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    }

    qsort(jobs, n, sizeof(Job), compare_profit);

    for (int i = 0; i < n; i++) {
        int slot = jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline;
        while (slot >= 1 && schedule[slot][0] != '\0') slot--;
        if (slot >= 1) {
            snprintf(schedule[slot], sizeof(schedule[slot]), "%s", jobs[i].id);
            totalProfit += jobs[i].profit;
        }
    }

    printf("\nFinal schedule:\n");
    for (int s = 1; s <= maxDeadline; s++)
        printf("Slot %d: %s\n", s, schedule[s][0] ? schedule[s] : "EMPTY");
    printf("Maximum total profit: %d\n", totalProfit);
    return 0;
}
