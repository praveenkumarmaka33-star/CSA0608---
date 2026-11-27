# TASK 3: Karatsuba Multiplication

def karatsuba(x, y):
    # Handle negative values
    if x < 0 and y < 0:
        return karatsuba(-x, -y)
    if x < 0:
        return -karatsuba(-x, y)
    if y < 0:
        return -karatsuba(x, -y)

    # Base case
    if x < 10 or y < 10:
        return x * y

    n = max(len(str(x)), len(str(y)))
    half = n // 2
    power = 10 ** half

    a, b = divmod(x, power)
    c, d = divmod(y, power)

    z0 = karatsuba(b, d)
    z2 = karatsuba(a, c)
    z1 = karatsuba(a + b, c + d) - z2 - z0

    return z2 * (power ** 2) + z1 * power + z0


def main():
    x = int(input("Enter first integer: "))
    y = int(input("Enter second integer: "))
    print("Product:", karatsuba(x, y))


if __name__ == "__main__":
    main()
