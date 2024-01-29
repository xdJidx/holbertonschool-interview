#ifndef SANDPILES_H
#define SANDPILES_H


/**
 * topple - Topple the sandpile
 * @grid: 3x3 grid
 */
void topple(int grid[3][3]);

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3]);

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3]);

#endif /* SANDPILES_H */
