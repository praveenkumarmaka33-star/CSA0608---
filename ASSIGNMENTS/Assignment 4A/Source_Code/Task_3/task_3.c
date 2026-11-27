#include <stdio.h>

#define MAXN 100
#define MAXC 1000

int main(void) {
    int n, capacity, weight[MAXN + 1], value[MAXN + 1];
    int dp[MAXN + 1][MAXC + 1];

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN) return 1;
    printf("Enter capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity < 0 || capacity > MAXC) return 1;

    for (int i = 1; i <= n; i++) {
        printf("Enter item ID number, weight and value: ");
        int id;
        scanf("%d %d %d", &id, &weight[i], &value[i]);
        if (weight[i] <= 0 || value[i] < 0) return 1;
    }

    for (int w = 0; w <= capacity; w++) dp[0][w] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i] <= w) {
                int include = value[i] + dp[i - 1][w - weight[i]];
                if (include > dp[i][w]) dp[i][w] = include;
            }
        }
    }

    printf("\nMaximum value: %d\n", dp[n][capacity]);
    printf("Selected items (input order): ");
    int w = capacity, selected[MAXN], count = 0;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[count++] = i;
            w -= weight[i];
        }
    }
    if (count == 0) printf("None");
    for (int k = count - 1; k >= 0; k--)
        printf("Item%d ", selected[k]);
    printf("\n");
    return 0;
}
