#!/usr/bin/python3
"""
Module pour générer le Triangle de Pascal.
"""


def pascal_triangle(n):
    """
    Retourne une liste représentant le triangle de Pascal de taille n.

    Args:
        n (int): Le nombre de lignes du triangle de Pascal à générer.

    Returns:
        List[List[int]]: Une liste de listes d'entiers représentant
        le triangle de Pascal.
    """
    pascal_list = []
    if n <= 0:
        return pascal_list
    for i in range(n):
        row = [1]
        if pascal_list:
            last_row = pascal_list[-1]
            row.extend([sum(pair) for pair in zip(last_row, last_row[1:])])
            row.append(1)
        pascal_list.append(row)
    return pascal_list
