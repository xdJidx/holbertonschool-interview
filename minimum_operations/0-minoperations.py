#!/usr/bin/python3
"""
0-Minimum Operations
"""

def minOperations(n):
    if n <= 1:
        return 0

    # Initialize the number of operations to 0
    operations = 0
    # Initialize the current clipboard content to 1 H
    clipboard = 1
    # Initialize the current file content to 1 H
    file_content = 1

    while file_content < n:
        if n % file_content == 0:
            # If the current file content is a divisor of n,
            # perform a Copy All operation and update the clipboard
            clipboard = file_content
            operations += 1

        # Perform a Paste operation and update the file content
        file_content += clipboard
        operations += 1

    return operations