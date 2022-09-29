#!/usr/bin/python3
""" Task Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """ Rotate 2D Matrix
        Given an n x n 2D matrix, rotate it 90 degrees clockwise.

        Do not return anything. The matrix must be edited in-place.
    """
    lenMatrix = len(matrix)
    for i in range(lenMatrix//2):
        for j in range(i, lenMatrix-1):
            matrix[i][j], matrix[
                j][lenMatrix-1] = matrix[j][lenMatrix-1], matrix[i][j]
            matrix[i][j], matrix[lenMatrix-1][lenMatrix-1-j+i] = matrix[
                lenMatrix-1][lenMatrix-1-j+i], matrix[i][j]
            matrix[i][j], matrix[lenMatrix-1-j+i][i] = matrix[
                lenMatrix-1-j+i][i], matrix[i][j]
        lenMatrix -= 1
