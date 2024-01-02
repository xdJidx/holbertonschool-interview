#!/usr/bin/python3
""" Lockboxes """

from typing import List


def canUnlockAll(boxes: List[List[int]]) -> bool:
    """ Determines if all the boxes can be opened. """
    if not boxes or len(boxes) == 0:
        return False

    # Initialize unlocked boxes (the first box is unlocked)
    unlocked_boxes = [False] * len(boxes)
    unlocked_boxes[0] = True

    # Initialize available keys with the keys from the first box
    keys = boxes[0]

    # Traverse available keys
    while keys:
        current_key = keys.pop()  # Take a key from the list

        # Check if the key opens a new unopened box
        if current_key < len(boxes) and not unlocked_boxes[current_key]:
            unlocked_boxes[current_key] = True  # Unlock the corresponding box
            keys.extend(boxes[current_key])  # Add newly found keys

    # Check if all boxes are unlocked
    return all(unlocked_boxes)
