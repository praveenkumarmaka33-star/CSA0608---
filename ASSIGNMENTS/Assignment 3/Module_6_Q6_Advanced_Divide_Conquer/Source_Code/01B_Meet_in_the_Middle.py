# TASK 6B: Subset Sum using Meet in the Middle

def subset_sums(values):
    sums = [0]
    for value in values:
        sums += [current + value for current in sums]
    return sums


def meet_in_the_middle(arr, target):
    mid = len(arr) // 2
    left_sums = subset_sums(arr[:mid])
    right_sums = set(subset_sums(arr[mid:]))

    for value in left_sums:
        if target - value in right_sums:
            return True
    return False


def main():
    arr = list(map(int, input("Enter integers separated by spaces: ").split()))
    target = int(input("Enter target sum: "))
    if meet_in_the_middle(arr, target):
        print("A subset with the target sum exists.")
    else:
        print("No subset with the target sum exists.")


if __name__ == "__main__":
    main()
