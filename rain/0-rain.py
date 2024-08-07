#!/usr/bin/python3
"""0-rain"""


def rain(walls):
    """
    Calculate the amount of water retained after raining.

    Args:
    walls (list of int): A list of non-negative integers
    representing the heights of walls with unit width 1.

    Returns:
    int: The total amount of rainwater retained.

    Notes:
    - If the list is empty, it returns 0.
    - The ends of the list (before index 0 and
      after index walls[-1]) are not considered
      walls, meaning they will not retain water.
    """

    if not walls:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    total_water = 0

    # Calculate the maximum height of walls to the left of each position
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Calculate the maximum height of walls to the right of each position
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate the amount of water retained at each position
    for i in range(n):
        total_water += max(0, min(left_max[i], right_max[i]) - walls[i])

    return total_water
