#!/usr/bin/python3
""" This is one of the most common " backtracking" problems:
    placing N queens on an NxN chessboard so that no queen
    can defeat another queen.

    We first place the first queen in any arbitrary location and
    then place the next queen in any of the safe locations.
    We continue this process until the number of unplaced queens
    is zero (a solution is found) or no safe place is left. If no
    safe place is left, we change the position of the previously placed
    queen.

    Source:
    https://www.codesdope.com/blog/article/backtracking-explanation-and-n-queens-problem/

"""

from sys import exit, argv


def val_input(args):
    """ Method to validate input arguments. args is sys.argv
    """
    if (len(args) == 2):
        try:
            # if N is not an integer
            num = int(args[1])
        except Exception:
            print("N must be a number")
            exit(1)
        # if N is smaller than 4
        if num < 4:
            print("N must be at least 4")
            exit(1)
        return num
    else:
        # if the user called the program with the
        # wrong number of arguments.
        print("Usage: nqueens N")
        exit(1)


def print_board(board):
    """ print_board
    """
    new_list = []
    for i, row in enumerate(board):
        value = []
        for j, col in enumerate(row):
            if col == 1:
                value.append(i)
                value.append(j)
        new_list.append(value)

    print(new_list)


def isSafe(board, row, col, number):
    """ This function to check if the cell is under
        attack by any other queen or not.
    """

    # Check this row in the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, number, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def N_queen(board, col, number):
    """ Method to show of the all the posibilites to solve the problem
    """

    if (col == number):
        print_board(board)
        return True
    res = False
    for i in range(number):

        if (isSafe(board, i, col, number)):

            # Place this queen in board[i][col]
            board[i][col] = 1

            # Make result true if any placement
            # is possible
            res = N_queen(board, col + 1, number) or res

            board[i][col] = 0
            # the loop will place the queen
            # on some another position this time

    return res


def solve(number):
    """ Find all the posibilities if exists
    """
    board = [[0 for i in range(number)]for i in range(number)]

    if not N_queen(board, 0, number):
        return False

    return True


if __name__ == "__main__":
    """ Top-level code environment
    """

    number = val_input(argv)
    solve(number)
