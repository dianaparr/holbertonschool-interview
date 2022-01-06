#!/usr/bin/python3
""" Module call minOperations """

import math


def minOperations(n):
    """ Method that calculates the fewest number of operations needed
    to result in exactly n H characters in the file.

    Parameter:
        n -> integer that represents the number of total H characters

    Return value**:
        An integer

    **If n is impossible to achieve, return 0 """

    operationsAccums = 0

    # if n is not integer or is less than 2
    if n < 2 or type(n) != int:
        return 0

    # run a loop from 2 to sqrt(n) and check if any number in range
    # (2-sqrt(n)) divides n
    for x in range(2, int(math.sqrt(n) + 1)):
        while n % x == 0:
            operationsAccums += x
            n = n // x

    # base case -> n = 1
    if n > 1:
        operationsAccums += n

    return operationsAccums
