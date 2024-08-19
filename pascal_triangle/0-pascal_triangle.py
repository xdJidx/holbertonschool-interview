#!/usr/bin/python3
""" Triangle de Pascal """


def pascal_triangle(n):
    if n <= 0:
        return []

    triangle = []

    for i in range(n):
        # Commencer chaque ligne avec un 1
        row = [1] * (i + 1)
        for j in range(1, i):
            # Chaque valeur est la somme des deux valeurs directement au-dessus
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
