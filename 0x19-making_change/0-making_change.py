#!/usr/bin/python3
""" Making change
"""


def makeChange(coins, total):
    """Determine the fewest number of coins needed
    to meet a given amount total."""
    if total <= 0:
        return 0

    coins.sort()
    coins.reverse()
    fewest = 0
    for coin in coins:
        if total <= 0:
            break
        buff = total // coin
        fewest += buff
        total -= (buff * coin)

    if total != 0:
        return -1

    return fewest
