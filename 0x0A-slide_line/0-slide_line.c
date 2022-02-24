#include "slide_line.h"

/**
 * slide_line - function that slides and merges an array of integers
 * @line: points to an array of integers
 * @size: size of the array
 * @direction: must be slided & merged to the direction represented
 *              SLIDE_LEFT and SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    /* convert tipe size to int */
    int size_ = size;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);
    if (direction == SLIDE_LEFT)
        slide_line_left(line, size_);
    else
        slide_line_right(line, size_);
    return (1);
}

/**
 * slide_line_left - helper function that slides and merges an array of integers
 *                  left direction
 * @line: points to an array of integers
 * @size_: size of the array
 *
 * Return: None
 */
void slide_line_left(int *line, int size_)
{
    /* temp in position zero to the array */
    int i = 0, j, temp = line[0];

    for (; i < size_; i++)
    {
        if (line[i])
        {
            if (i != 0)
            {
                if (line[i] == temp)
                {
                    line[j] = line[i] + temp;
                    temp = 0;
                    j++;
                }
                else
                {
                    if (temp != 0)
                    {
                        line[j] = temp;
                        j++;
                    }
                    if (i == size_ - 1)
                    {
                        line[j] = line[i];
                        j++;
                    }
                    temp = line[i];
                }
            }
        }
    }
    if (j == 0)
    {
        line[j] = temp;
        j++;
    }
    while (j < size_)
        line[j++] = 0;
}

/**
 * slide_line_rigth - helper function that slides and merges an array of integers
 *                  rigth direction
 * @line: points to an array of integers
 * @size_: size of the array
 *
 * Return: None
 */
void slide_line_right(int *line, int size_)
{
    /* temp in position size - 1 to the array (last position) */
    int i, j, temp;

    j = size_ - 1;
    temp = line[j];

    for (i = size_ - 1; i >= 0; i--)
    {
        if (line[i])
        {
            if (i != size_ - 1)
            {
                if (line[i] == temp)
                {
                    line[j] = line[i] + temp;
                    temp = 0;
                    j--;
                }
                else
                {
                    if (temp != 0)
                    {
                        line[j] = temp;
                        j--;
                    }
                    if (i == 0)
                    {
                        line[j] = line[i];
                        j--;
                    }
                    temp = line[i];
                }
            }
        }
    }
    if (j == size_ - 1)
    {
        line[j] = temp;
        j--;
    }
    while (j >= 0)
        line[j--] = 0;
}
