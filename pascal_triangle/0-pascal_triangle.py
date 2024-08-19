#!/usr/bin/python3
"""Triangle de Pascal"""


def pascal_triangle(n):
    """
    Generate Pascal's Triangle up to the nth row.

    Args:
        n (int): The number of rows of the Pascal's Triangle to generate.

    Returns:
        List[List[int]]: A list of lists of integers representing
        the Pascal's Triangle.
    """
    if n <= 0:
        return []

    triangle = []

    for i in range(n):
        # Start each row with a 1
        row = [1] * (i + 1)
        for j in range(1, i):
            # Each value is the sum of the two values directly above it
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(row)

    return triangle


if __name__ == "__main__":
    def print_triangle(triangle):
        """
        Print the triangle
        """
        for row in triangle:
            print("[{}]".format(",".join([str(x) for x in row])))

    print_triangle(pascal_triangle(5))
