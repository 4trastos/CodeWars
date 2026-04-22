#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int slide(int row, int col, const int pyramid[], int rows, int memo[][rows])
{
    int current = 0;
    int left = 0;
    int right = 0;
    int pos = 0;
    
    if (memo[row][col] != -1)
        return memo[row][col];
    
    if (row == rows - 1)
    {
        pos = row * (row + 1) / 2 + col;
        memo[row][col] = pyramid[pos];
        return memo[row][col];
    }
    
    pos = row * (row + 1) / 2 + col;
    current = pyramid[pos];
    left = slide(row + 1, col, pyramid, rows, memo);
    right = slide(row + 1, col + 1, pyramid, rows, memo);
    
    if (left > right)
        memo[row][col] = current + left;
    else
        memo[row][col] = current + right;
    
    return memo[row][col];
}

int pyramid_slide_down(int num_elements, const int pyramid[num_elements], int rows)
{
    int memo[rows][rows];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            memo[i][j] = -1;
    
    return slide(0, 0, pyramid, rows, memo);
}