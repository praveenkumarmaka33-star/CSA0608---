# TASK 7: Maximum Subarray using Divide and Conquer

def max_crossing_sum(arr, low, mid, high):
    total = 0
    left_sum = float("-inf")
    for i in range(mid, low - 1, -1):
        total += arr[i]
        left_sum = max(left_sum, total)

    total = 0
    right_sum = float("-inf")
    for i in range(mid + 1, high + 1):
        total += arr[i]
        right_sum = max(right_sum, total)

    return left_sum + right_sum


def max_subarray_sum(arr, low, high):
    if low == high:
        return arr[low]

    mid = (low + high) // 2
    left_sum = max_subarray_sum(arr, low, mid)
    right_sum = max_subarray_sum(arr, mid + 1, high)
    crossing_sum = max_crossing_sum(arr, low, mid, high)

    return max(left_sum, right_sum, crossing_sum)


def main():
    arr = list(map(int, input("Enter integers separated by spaces: ").split()))
    if not arr:
        print("Please enter at least one number.")
        return
    print("Maximum subarray sum:", max_subarray_sum(arr, 0, len(arr) - 1))


if __name__ == "__main__":
    main()
