
/*
 * CO1 Assignment: Student registration-number search benchmark
 * Algorithms: Linear search, recursive binary search, hash-table search.
 * Build: gcc -O2 -std=c11 -Wall -Wextra benchmark.c -o benchmark
 *
 * Timing is measured over batches with clock(); comparison/probe counts
 * are reported separately. IDs are unique integers in ascending order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

typedef struct { int found; long long comparisons; int index; } SearchResult;
typedef struct { int key; unsigned char used; } Entry;

static long long cmp_count;
static long long probe_count;

static int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

SearchResult linear_search(const int *a, int n, int target) {
    SearchResult r = {0, 0, -1};
    for (int i = 0; i < n; ++i) {
        r.comparisons++;
        if (a[i] == target) { r.found = 1; r.index = i; break; }
    }
    return r;
}

static int recursive_binary_impl(const int *a, int low, int high,
                                 int target, long long *comparisons) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    (*comparisons)++;
    if (a[mid] == target) return mid;
    if (target < a[mid])
        return recursive_binary_impl(a, low, mid - 1, target, comparisons);
    return recursive_binary_impl(a, mid + 1, high, target, comparisons);
}

SearchResult recursive_binary_search(const int *a, int n, int target) {
    SearchResult r = {0, 0, -1};
    r.index = recursive_binary_impl(a, 0, n - 1, target, &r.comparisons);
    r.found = (r.index >= 0);
    return r;
}

static uint64_t hash_int(int key) {
    uint64_t x = (uint32_t)key;
    x ^= x >> 16;
    x *= UINT64_C(0x7feb352d);
    x ^= x >> 15;
    x *= UINT64_C(0x846ca68b);
    x ^= x >> 16;
    return x;
}

/* Linear probing, capacity must be a power of two and > number of keys. */
static int hash_insert(Entry *table, size_t cap, int key) {
    size_t i = (size_t)hash_int(key) & (cap - 1);
    while (table[i].used) {
        if (table[i].key == key) return 0;
        i = (i + 1) & (cap - 1);
    }
    table[i].key = key;
    table[i].used = 1;
    return 1;
}

SearchResult hash_search(const Entry *table, size_t cap, int target) {
    SearchResult r = {0, 0, -1};
    size_t i = (size_t)hash_int(target) & (cap - 1);
    while (table[i].used) {
        r.comparisons++; /* one stored-key equality check per occupied slot */
        if (table[i].key == target) { r.found = 1; break; }
        i = (i + 1) & (cap - 1);
        if (r.comparisons > (long long)cap) break;
    }
    return r;
}

static double elapsed_ms(clock_t start, clock_t end) {
    return 1000.0 * (double)(end - start) / (double)CLOCKS_PER_SEC;
}

static void write_row(FILE *f, int n, const char *algorithm,
                      const char *scenario, int target, SearchResult r,
                      double total_ms, int repetitions) {
    fprintf(f, "%d,%s,%s,%d,%d,%lld,%.6f,%.9f,%d\n",
            n, algorithm, scenario, target, r.found, r.comparisons,
            total_ms, total_ms / repetitions, repetitions);
}

int main(void) {
    const int sizes[] = {1000, 10000, 100000, 1000000};
    const int nsizes = (int)(sizeof(sizes)/sizeof(sizes[0]));
    const int repetitions = 100;
    FILE *csv = fopen("results.csv", "w");
    if (!csv) { perror("results.csv"); return 1; }
    fprintf(csv, "n,algorithm,scenario,target,found,comparisons,total_batch_ms,ms_per_search,repetitions\n");

    for (int s = 0; s < nsizes; ++s) {
        int n = sizes[s];
        int *a = (int *)malloc((size_t)n * sizeof(int));
        if (!a) { fprintf(stderr, "Allocation failed for n=%d\n", n); fclose(csv); return 1; }
        for (int i = 0; i < n; ++i) a[i] = 202300000 + i;

        /* Binary-search preprocessing: qsort; time is explicitly reported. */
        clock_t sort_start = clock();
        qsort(a, (size_t)n, sizeof(int), cmp_int);
        clock_t sort_end = clock();
        double sort_ms = elapsed_ms(sort_start, sort_end);

        size_t cap = 1;
        while (cap < (size_t)n * 2U) cap <<= 1;
        Entry *table = (Entry *)calloc(cap, sizeof(Entry));
        if (!table) { fprintf(stderr, "Hash allocation failed\n"); free(a); fclose(csv); return 1; }

        clock_t build_start = clock();
        for (int i = 0; i < n; ++i) hash_insert(table, cap, a[i]);
        clock_t build_end = clock();
        double build_ms = elapsed_ms(build_start, build_end);

        printf("\nN=%d | binary sort preprocessing=%.3f ms | hash build preprocessing=%.3f ms | hash capacity=%zu | load factor=%.3f\n",
               n, sort_ms, build_ms, cap, (double)n/(double)cap);

        /* Best/average/worst/miss scenarios. Binary best uses midpoint key. */
        int targets[4] = {a[0], a[n/3], a[n-1], 999999999};
        const char *scenarios[4] = {"best_or_first", "successful_one_third", "last_record", "unsuccessful"};

        for (int k = 0; k < 4; ++k) {
            int target = targets[k];
            SearchResult lr = linear_search(a, n, target);
            SearchResult br = recursive_binary_search(a, n, target);
            SearchResult hr = hash_search(table, cap, target);

            /* Batch timing: same target repeated; prevent compiler from eliding work. */
            volatile int sink = 0;
            clock_t t0 = clock();
            for (int rep = 0; rep < repetitions; ++rep) sink += linear_search(a, n, target).found;
            clock_t t1 = clock();
            double lms = elapsed_ms(t0, t1);
            t0 = clock();
            for (int rep = 0; rep < repetitions; ++rep) sink += recursive_binary_search(a, n, target).found;
            t1 = clock();
            double bms = elapsed_ms(t0, t1);
            t0 = clock();
            for (int rep = 0; rep < repetitions; ++rep) sink += hash_search(table, cap, target).found;
            t1 = clock();
            double hms = elapsed_ms(t0, t1);
            (void)sink;

            write_row(csv, n, "Linear", scenarios[k], target, lr, lms, repetitions);
            write_row(csv, n, "RecursiveBinary", scenarios[k], target, br, bms, repetitions);
            write_row(csv, n, "HashTable", scenarios[k], target, hr, hms, repetitions);
            printf("  %-20s | L cmp=%-8lld B cmp=%-3lld H probes=%-4lld | found=%d/%d/%d\n",
                   scenarios[k], lr.comparisons, br.comparisons, hr.comparisons,
                   lr.found, br.found, hr.found);
        }
        free(table);
        free(a);
    }
    fclose(csv);
    puts("\nBenchmark complete. Detailed measurements saved to results.csv");
    return 0;
}
