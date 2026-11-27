#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[20];
    double weight, value, ratio, fraction;
} Package;

int compare_ratio(const void *a, const void *b) {
    const Package *x = (const Package *)a;
    const Package *y = (const Package *)b;
    if (x->ratio < y->ratio) return 1;
    if (x->ratio > y->ratio) return -1;
    return 0;
}

int main(void) {
    int n;
    double capacity, remaining, total = 0.0;
    Package p[100];

    printf("Enter number of packages: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) return 1;
    printf("Enter vehicle capacity: ");
    if (scanf("%lf", &capacity) != 1 || capacity < 0) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter package ID, weight and value: ");
        scanf("%19s %lf %lf", p[i].id, &p[i].weight, &p[i].value);
        if (p[i].weight <= 0 || p[i].value < 0) return 1;
        p[i].ratio = p[i].value / p[i].weight;
        p[i].fraction = 0.0;
    }

    qsort(p, n, sizeof(Package), compare_ratio);
    remaining = capacity;

    for (int i = 0; i < n && remaining > 0; i++) {
        if (p[i].weight <= remaining) {
            p[i].fraction = 1.0;
            remaining -= p[i].weight;
            total += p[i].value;
        } else {
            p[i].fraction = remaining / p[i].weight;
            total += p[i].fraction * p[i].value;
            remaining = 0.0;
        }
    }

    printf("\nSelected fractions (descending value/weight):\n");
    for (int i = 0; i < n; i++)
        if (p[i].fraction > 0)
            printf("%s: %.2f (%.2f%%)\n", p[i].id, p[i].fraction, p[i].fraction * 100);
    printf("Maximum total value: %.2f\n", total);
    printf("Unused capacity: %.2f\n", remaining);
    return 0;
}
