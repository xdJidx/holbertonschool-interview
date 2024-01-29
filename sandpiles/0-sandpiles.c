#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    
    // Add the two sandpiles together
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Topple the sandpile until it becomes stable
    while (1)
    {
        // Print the sandpile before each toppling round if it's unstable
        if (!is_stable(grid1))
        {
            printf("=\n");
            print_grid(grid1);
        }

        topple(grid1);

        // Check if the sandpile is stable after toppling
        if (is_stable(grid1))
            break;
    }
}

/**
 * is_stable - Check if the sandpile is stable
 * @grid: 3x3 grid
 * @return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 0;
        }
    }

    return 1;
}

/**
 * topple - Topple the sandpile
 * @grid: 3x3 grid
 */
void topple(int grid[3][3])
{
    int i, j;
    int toppled[3][3] = {{0}};

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] >= 4)
            {
                toppled[i][j] -= 4;
                if (i + 1 < 3)
                    toppled[i + 1][j]++;
                if (i - 1 >= 0)
                    toppled[i - 1][j]++;
                if (j + 1 < 3)
                    toppled[i][j + 1]++;
                if (j - 1 >= 0)
                    toppled[i][j - 1]++;
            }
        }
    }

    // Update the original grid with the toppled values
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid[i][j] += toppled[i][j];
        }
    }
}
