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
	int size_arr = size;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	if (direction == SLIDE_LEFT)
		slide_line_left(line, size_arr);
	else
		slide_line_right(line, size_arr);
	return (1);
}

/**
 * slide_line_left - helper function that slides and merges
 *                   an array of integers left direction
 * @line: points to an array of integers
 * @size_arr: size of the array
 *
 * Return: None
 */
void slide_line_left(int *line, int size_arr)
{
	/*j traverse the array*/
	int i, j;

	for (i = 0, j = i + 1; j < size_arr; j++)
	{
		if (line[j] == 0)
			continue;
		if (line[i] == line[j])
		{
			line[i] += line[j];
			line[j] = 0;
			i++;
		}
		if (line[i] != line[j])
		{
			if (line[i] == 0)
			{
				line[i] += line[j];
				line[j] = 0;
			}
			else
			{
				i++;
				if (i != j)
				{
					line[i] += line[j];
					line[j] = 0;
				}
			}
		}
	}
}

/**
 * slide_line_right - helper function that slides and merges
 *                    an array of integers rigth direction
 * @line: points to an array of integers
 * @size_arr: size of the array
 *
 * Return: None
 */
void slide_line_right(int *line, int size_arr)
{
	/* i in position size - 1 to the array (last position) */
	/*j one position of the "reverse"*/
	int i, j;

	for (i = size_arr - 1, j = i - 1; j >= 0; j--)
	{
		if (line[j] == 0)
			continue;
		if (line[i] == line[j])
		{
			line[i] += line[j];
			line[j] = 0;
			i--;
		}
		if (line[i] != line[j])
		{
			if (line[i] == 0)
			{
				line[i] += line[j];
				line[j] = 0;
			}
			else
			{
				i--;
				if (i != j)
				{
					line[i] += line[j];
					line[j] = 0;
				}
			}
		}
	}
}
