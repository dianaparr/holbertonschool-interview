#!/usr/bin/python3
"""
0x19-Making change
"""


def makeChange(coins, total):
    """Determine the fewest number of coins needed
    to meet a given amount total."""
    if total <= 0:
        return 0

    coins.sort(reverse=True)

    fewest = 0
    for coin in coins:
        if total <= 0:
            break
        buff = total // coin
        fewest += buff
        total -= (buff * coin)

    if total != 0 or fewest == 0:
        return -1

    return fewest
