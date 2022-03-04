#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: is the level of the Menger Sponge to draw
 *
 * Return: None
 */
void menger(int level)
{
	int y = 0, x, size_tot;

	if (level < 0)
		return;

	/* The size of a level N Menger sponge is calculated as follows: 3^N */
	size_tot = pow(3, level);
	for (; y < size_tot; y++)
	{
		for (x = 0; x < size_tot; x++)
		{
			putchar(_draw_sponge_(y, x));
		}
		putchar('\n');
	}

}


/**
 * _draw_sponge_ - function to draw the sponge
 *
 * @column: columns
 * @rows: rows
 *
 * Return: None
 */
char _draw_sponge_(int column, int rows)
{
	while (column || rows)
	{
		if (column % 3 == 1 && rows % 3 == 1)
			return (' ');
		column = column / 3;
		rows = rows / 3;
	}
	return ('#');
}
