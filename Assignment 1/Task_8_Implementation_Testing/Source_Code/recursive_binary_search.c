/* Standalone Recursive Binary Search; input must be sorted */
int recursive_binary_search(const int *a, int low, int high,
                            int target, long long *comparisons) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    ++(*comparisons);
    if (a[mid] == target) return mid;
    if (target < a[mid])
        return recursive_binary_search(a, low, mid - 1, target, comparisons);
    return recursive_binary_search(a, mid + 1, high, target, comparisons);
}
