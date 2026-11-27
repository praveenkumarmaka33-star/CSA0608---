# TASK 5: Closest Pair of Points

import math


def distance(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])


def closest_pair(points):
    points = sorted(points, key=lambda p: p[0])

    def solve(px):
        n = len(px)
        if n <= 3:
            best = (float("inf"), None, None)
            for i in range(n):
                for j in range(i + 1, n):
                    d = distance(px[i], px[j])
                    if d < best[0]:
                        best = (d, px[i], px[j])
            return best

        mid = n // 2
        left = px[:mid]
        right = px[mid:]
        mid_x = px[mid][0]

        best_left = solve(left)
        best_right = solve(right)
        best = best_left if best_left[0] <= best_right[0] else best_right

        strip = [p for p in px if abs(p[0] - mid_x) < best[0]]
        strip.sort(key=lambda p: p[1])

        for i in range(len(strip)):
            j = i + 1
            while j < len(strip) and strip[j][1] - strip[i][1] < best[0]:
                d = distance(strip[i], strip[j])
                if d < best[0]:
                    best = (d, strip[i], strip[j])
                j += 1
        return best

    if len(points) < 2:
        return None
    return solve(points)


def main():
    n = int(input("Enter number of points: "))
    if n < 2:
        print("Enter at least two points.")
        return

    points = []
    for i in range(n):
        x, y = map(float, input(f"Enter x and y for point {i + 1}: ").split())
        points.append((x, y))

    result = closest_pair(points)
    d, p1, p2 = result
    print("Closest points:", p1, "and", p2)
    print("Minimum distance:", f"{d:.6f}")


if __name__ == "__main__":
    main()
