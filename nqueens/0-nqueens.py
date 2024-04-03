#!/usr/bin/python3
""" N-Queens problem solver """
import sys

def is_safe(board, row, col):
    """_summary_

    Args:
        board (_type_): _description_
        row (_type_): _description_
        col (_type_): _description_

    Returns:
        _type_: _description_
    """
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True

def solve_n_queens(n):
    """_summary_

    Args:
        n (_type_): _description_

    Returns:
        _type_: _description_
    """
    board = [-1] * n
    solutions = []

    def backtrack(row):
        if row == n:
            solutions.append(list(board))
            return

        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                backtrack(row + 1)
                board[row] = -1

    backtrack(0)
    return solutions

def print_solutions(solutions):
    """_summary_

    Args:
        solutions (_type_): _description_
    """
    for solution in solutions:
        print(list(map(list, enumerate(solution))))

def main():
    """_summary_"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_n_queens(n)
    print_solutions(solutions)

if __name__ == "__main__":
    main()
