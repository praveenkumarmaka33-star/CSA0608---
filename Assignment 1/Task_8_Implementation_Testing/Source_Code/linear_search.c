/* Standalone Linear Search implementation */
int linear_search(const int *a, int n, int target, long long *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; ++i) {
        ++(*comparisons);
        if (a[i] == target) return i;
    }
    return -1;
}
