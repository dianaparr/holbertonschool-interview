#ifndef SANDPILES_SUM
#define SANDPILES_SUM

#include <stdlib.h>
#include <stdio.h>

/* static void print_grid_sum(int grid1[3][3], int grid2[3][3]); */
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
int check_stability(int grid1[3][3]);


#endif /* SANDPILES_SUM */
