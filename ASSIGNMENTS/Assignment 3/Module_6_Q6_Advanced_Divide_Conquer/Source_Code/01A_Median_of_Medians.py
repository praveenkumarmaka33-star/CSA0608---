# TASK 6A: Selection using Median of Medians

def median_of_medians(arr, k):
    """Return the k-th smallest element (1-based k)."""
    if k < 1 or k > len(arr):
        raise ValueError("k is outside the valid range")

    if len(arr) <= 5:
        return sorted(arr)[k - 1]

    groups = [arr[i:i + 5] for i in range(0, len(arr), 5)]
    medians = [sorted(group)[len(group) // 2] for group in groups]
    pivot = median_of_medians(medians, (len(medians) + 1) // 2)

    lower = [x for x in arr if x < pivot]
    equal = [x for x in arr if x == pivot]
    higher = [x for x in arr if x > pivot]

    if k <= len(lower):
        return median_of_medians(lower, k)
    if k <= len(lower) + len(equal):
        return pivot
    return median_of_medians(higher, k - len(lower) - len(equal))


def main():
    arr = list(map(int, input("Enter integers separated by spaces: ").split()))
    if not arr:
        print("Please enter at least one number.")
        return
    k = int(input(f"Enter k (1 to {len(arr)}) to find the k-th smallest element: "))
    try:
        print(f"The {k}-th smallest element is:", median_of_medians(arr, k))
    except ValueError as error:
        print(error)


if __name__ == "__main__":
    main()
