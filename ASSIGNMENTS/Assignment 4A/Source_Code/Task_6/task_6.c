#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[20];
    int start, finish, value, p;
} Job;

int compare_finish(const void *a, const void *b) {
    const Job *x = (const Job *)a;
    const Job *y = (const Job *)b;
    if (x->finish != y->finish) return x->finish - y->finish;
    return x->start - y->start;
}

int main(void) {
    int n, dp[101], selected[101], count = 0;
    Job jobs[101];

    printf("Enter number of jobs: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter job ID, start, finish and energy-saving value: ");
        scanf("%19s %d %d %d", jobs[i].id, &jobs[i].start,
              &jobs[i].finish, &jobs[i].value);
        if (jobs[i].finish < jobs[i].start || jobs[i].value < 0) return 1;
    }

    qsort(jobs, n, sizeof(Job), compare_finish);

    for (int j = 0; j < n; j++) {
        jobs[j].p = 0;
        for (int i = 0; i < j; i++)
            if (jobs[i].finish <= jobs[j].start) jobs[j].p = i + 1;
    }

    dp[0] = 0;
    for (int j = 1; j <= n; j++) {
        int include = jobs[j - 1].value + dp[jobs[j - 1].p];
        int exclude = dp[j - 1];
        dp[j] = include > exclude ? include : exclude;
    }

    int j = n;
    while (j > 0) {
        int include = jobs[j - 1].value + dp[jobs[j - 1].p];
        if (include > dp[j - 1]) {
            selected[count++] = j - 1;
            j = jobs[j - 1].p;
        } else {
            j--;
        }
    }

    printf("\nJobs selected: ");
    if (count == 0) printf("None");
    for (int k = count - 1; k >= 0; k--)
        printf("%s ", jobs[selected[k]].id);
    printf("\nMaximum total energy saving: %d\n", dp[n]);
    return 0;
}
