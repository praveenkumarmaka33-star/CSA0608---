# TASK 1: Find Maximum and Minimum using Divide and Conquer

def find_min_max(arr, low, high):
    # Base case: one element
    if low == high:
        return arr[low], arr[low]

    # Base case: two elements
    if high == low + 1:
        if arr[low] < arr[high]:
            return arr[low], arr[high]
        return arr[high], arr[low]

    mid = (low + high) // 2
    min1, max1 = find_min_max(arr, low, mid)
    min2, max2 = find_min_max(arr, mid + 1, high)

    return min(min1, min2), max(max1, max2)


def main():
    arr = list(map(int, input("Enter integers separated by spaces: ").split()))
    if not arr:
        print("Please enter at least one number.")
        return

    minimum, maximum = find_min_max(arr, 0, len(arr) - 1)
    print("Minimum value:", minimum)
    print("Maximum value:", maximum)


if __name__ == "__main__":
    main()
