#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *factors(int n)
{
    char    *result = malloc(1000);
    int     i = 2;
    int     pos = 0;
    int     count = 0;

    while (i * i <= n)
    {
        count = 0;
        while (n % i == 0)
        {
            n /= i;
            count++;
        }
        if (count > 0)
        {
            if (count == 1)
                pos += sprintf(result + pos, "(%d)", i);
            else
                pos += sprintf(result + pos, "(%d**%d)", i, count);
        }
        i++;
    }

    if (n > 1)
        pos += sprintf(result + pos, "(%d)", n);

    return (result);
}