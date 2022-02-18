#!/usr/bin/python3
""" Module named 0-validate_utf8
    left-shift documentation: https://processing.org/reference/leftshift.html
"""


def validUTF8(data):
    """ Return: True if data is a valid UTF-8 encoding,
        else return False

        Each integer represents 1 byte of data, therefore you only
        need to handle the 8 least significant bits of each integer

        first bit significative equal 1: 1000 0000 (1 << 7)
        second bit significative equal 1: 0100 0000 (1 << 6)
    """
    counterBytes = 0
    shiftBitsLeft1 = 1 << 7
    shiftBitsLeft2 = 1 << 6
    for integerNum in data:
        bitsLeft = 1 << 7
        if counterBytes == 0:
            while integerNum & bitsLeft:
                counterBytes += 1
                bitsLeft = bitsLeft >> 1
            if counterBytes == 0:
                continue
            if counterBytes == 1 or counterBytes > 4:
                return False
        else:
            if not (integerNum & shiftBitsLeft1) and not (
                    integerNum & shiftBitsLeft2):
                return False
        counterBytes -= 1

    if counterBytes == 0:
        return True
    return False
