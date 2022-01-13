#include "sandpiles.h"

#define true 1
#define false 0

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: left 3x3 grid
 * @grid2: right 3x3 grid
 *
 * Return: none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* sum of grids: add in grid1 each element of grid2 */
	sum_grids(grid1, grid2);

	/* "When your function is done, grid1 must be stable" */
	while (check_stability(grid1) != true)
	{
		printf("=\n");
		print_grid(grid1);

		/* fill grid2 with zeros */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				grid2[i][j] = 0;
		}

		/* implement the Abelian sandpile model. */
		/* Source: https://rosettacode.org/wiki/Abelian_sandpile_model#C */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] >= 4)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid2[i - 1][j] += 1;
					if (i + 1 < 3)
						grid2[i + 1][j] += 1;
					if (j - 1 >= 0)
						grid2[i][j - 1] += 1;
					if (j + 1 < 3)
						grid2[i][j + 1] += 1;
				}
			}
		}
		sum_grids(grid1, grid2);
	}
}

/**
 * sum_grids - function that sum of content to one grid in other grid
 * @grid1: left 3x3 grid
 * @grid2: right 3x3 grid
 *
 * Return: none
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j;

	for ( ; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}


/**
 * check_stability - function that checks the stability of the grid,
 * when none of its cells contains more than 3 grains
 * @grid1: 3x3 grid
 *
 * Return: true if the stability of the grid exists or false if not stable.
 */
int check_stability(int grid1[3][3])
{
	int i = 0, j;

	for ( ; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (false);
		}
	}
	return (true);
}


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
