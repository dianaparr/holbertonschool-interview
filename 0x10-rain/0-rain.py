#!/usr/bin/python3
"""Add task 0"""


def rain(walls):
    """Function
    Params:
        - walls: list of non-negative integers
    Return: integer indicating total amount of rainwater retained
    """
    if len(walls) == 0 or type(walls) != list:
        return 0
    water = 0
    for index, mid in enumerate(walls):
        """ends of the list"""
        if index != 0 and index != (len(walls) - 1):
            left = max(walls[0:index])
            right = max(walls[index + 1:len(walls)])
            if mid < left and mid < right:
                water += min([left, right]) - mid
    return water
