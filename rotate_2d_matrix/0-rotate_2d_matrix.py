#!/usr/bin/python3
""""Rotate a 2D matrix by 90 degrees clockwise."""

def rotate_2d_matrix(matrix):
    n = len(matrix)
    
    # Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            # Swap elements matrix[i][j] and matrix[j][i]
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    
    # Reverse each row
    for i in range(n):
        matrix[i].reverse()
