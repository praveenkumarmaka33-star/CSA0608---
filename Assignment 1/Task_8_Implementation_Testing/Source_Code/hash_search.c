/* Open-addressed hash table with linear probing; table capacity is power of 2 */
#include <stddef.h>
typedef struct { int key; unsigned char used; } Entry;
int hash_search(const Entry *table, size_t capacity, int target,
                long long *key_comparisons) {
    *key_comparisons = 0;
    /* Use the same integer mixing function as benchmark.c. */
    unsigned long long x = (unsigned int)target;
    x ^= x >> 16; x *= 0x7feb352dULL;
    x ^= x >> 15; x *= 0x846ca68bULL; x ^= x >> 16;
    size_t i = (size_t)x & (capacity - 1);
    while (table[i].used) {
        ++(*key_comparisons);
        if (table[i].key == target) return (int)i;
        i = (i + 1) & (capacity - 1);
        if (*key_comparisons > (long long)capacity) break;
    }
    return -1;
}
