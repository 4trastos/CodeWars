#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


void    twoSum(unsigned count, const int numbers[count], int target, unsigned *index1, unsigned *index2)
{
    unsigned    i = 0;
    unsigned    x = 0;

    while (i < count)
    {
        x = i + 1;
        while (x < count)
        {
            if (numbers[i] + numbers[x] == target)
            {
                *index1 = i;
                *index2 = x;
                return;
            }
            x++;
        }
        i++;
    }
    *index1 = *index2 = 0;
    return;
}

int main(void)
{

    unsigned    count = 3;
    const int   numbers[3] = {3, 2, 4};
    int         target = 6;
    unsigned    index1;
    unsigned    index2;
    
    twoSum(count, numbers, target, &index1, &index2);

    printf("{%u, %u}\n", index1, index2);
    return (0);
}