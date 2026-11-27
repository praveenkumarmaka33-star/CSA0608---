# TASK 2: Merge Sort and Quick Sort

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result


def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    smaller = [x for x in arr if x < pivot]
    equal = [x for x in arr if x == pivot]
    greater = [x for x in arr if x > pivot]

    return quick_sort(smaller) + equal + quick_sort(greater)


def main():
    arr = list(map(int, input("Enter integers separated by spaces: ").split()))
    print("Original array:", arr)
    print("Merge Sort:", merge_sort(arr))
    print("Quick Sort:", quick_sort(arr))


if __name__ == "__main__":
    main()
