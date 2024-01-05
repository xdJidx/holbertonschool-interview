#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be unlocked using the provided keys.

    Args:
    - boxes: A list of lists. Each sublist represents a box containing keys
     to open other boxes.

    Returns:
    - True if all boxes can be unlocked, else False.
    """

    '''Check if the list is empty or null (no boxes to open)'''
    if not boxes or len(boxes) == 0:
        return False

    '''Initialize a list of already unlocked boxes,
      starting with the first box (index 0)'''
    unlocked_boxes = [0]

    '''Iterate through each unlocked box to find and use the keys'''
    for box in unlocked_boxes:
        '''Iterate through each key in the currently open box'''
        for key in boxes[box]:
            '''Add the key to the list if it opens a new box'''
            '''and if the key is within bounds (valid index)'''
            if key not in unlocked_boxes and key < len(boxes):
                unlocked_boxes.append(key)

    '''Compare the number of unlocked boxes to the total number of boxes'''
    '''Check if all boxes have been opened'''
    return len(unlocked_boxes) == len(boxes)
