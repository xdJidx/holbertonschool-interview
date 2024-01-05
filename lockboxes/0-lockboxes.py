#!/usr/bin/python3
"""
Lockboxes Module

This module provides a function 'canUnlockAll'
to determine if all the boxes can be opened.
"""

from typing import List


def canUnlockAll(boxes: List[List[int]]) -> bool:
    """
    Determines if all the boxes can be opened.

    Args :
        boxes (List[List[int]]):
         A list of lists where each inner list represents a box
           and contains keys to other boxes.

    Returns :
        bool: True if all boxes can be opened, False otherwise.
    """

    """Verify if all box are empty or null"""
    if not boxes or len(boxes) == 0:
        return False

    """Initialize unlocked boxes (the first box is unlocked)"""
    unlocked_boxes = [False] * len(boxes)
    unlocked_boxes[0] = True

    """Initialize available keys with the keys from the first box"""
    keys = boxes[0]

    """Traverse available keys"""
    while keys:
        """Take a key from the list"""
        current_key = keys.pop()

        """Check if the key opens a new unopened box"""
        if current_key < len(boxes) and not unlocked_boxes[current_key]:
            """Unlock the corresponding box"""
            unlocked_boxes[current_key] = True
            """Add newly found keys"""
            keys.extend(boxes[current_key])

    """Check if all boxes are unlocked"""
    return all(unlocked_boxes)
