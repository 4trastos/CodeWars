#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols)
{
    int     *toback;
    int     x = 0;
    int     y = 0;
    int     top = 0;
    int     bottom = rows - 1;
    int     left = 0;
    int     right = cols - 1;
    size_t  len = 0;
    size_t  i = 0;

    len = rows * cols;
    *outsz = len;
    toback = malloc(len * sizeof(int));
    if (!toback)
        return (NULL);
    while (top <= bottom && left <= right)
    {
        x = left;
        while (x <= right)
        {
            toback[i] = mx[top][x];
            x++;
            i++;
        }
        top++;
        y = top;
        while (y <= bottom)
        {
            toback[i] = mx[y][right];
            y++;
            i++;
        }
        right--;
        x = right;
        while (x >= left)
        {
            toback[i] = mx[bottom][x];
            x--;
            i++;
        }
        bottom--;
        y = bottom;
        while (y >= top)
        {
            toback[i] = mx[y][left];
            y--;
            i++;
        }
        left++;
    }
    return (toback);
}

// int main(void)
// {
//     const int row0[] = {1, 2, 3};
//     const int row1[] = {4, 5, 6};
//     const int row2[] = {7, 8, 9};
//     const int *mx[] = {row0, row1, row2};
//     size_t outsz = 0;
//     int *result = snail(&outsz, mx, 3, 3);
//     printf("outsz: %zu\n", outsz);
//     printf("result: ");
//     for (size_t i = 0; i < outsz; i++)
//         printf("%d ", result[i]);
//     printf("\n");
//     free(result);
//     return (0);
// }
