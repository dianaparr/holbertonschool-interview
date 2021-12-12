#!/usr/bin/python3
""" Module name 0-lockboxes """

def canUnlockAll(boxes):
    """ This exercise is the one example for the job interview.
        You have n number of locked boxes in front of you. Each box is
        numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

        Write a method that determines if all the boxes can be opened.

        Parameter:
            boxes ->  list of lists

        Return:
            True if all boxes can be opened, else return False
    """
    #unordered collection of unique elements
    keysBoxes = set()

    #initial check
    if boxes is None or len(boxes) == 0:
        return False

    #method adds a counter to an iterable and returns it in a form of enumerating object
    for nextKey, box in enumerate(boxes):
        nextKey += 1
        for key in box:
            if key < len(boxes):
                keysBoxes.add(key)
                keysBoxes.update(boxes[key])
            if len(keysBoxes) == len(boxes) or len(keysBoxes) == len(boxes) - 1:
                return True
        if nextKey not in keysBoxes:
            return False
