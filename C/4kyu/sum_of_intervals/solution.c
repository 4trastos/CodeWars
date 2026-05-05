#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

struct interval {
    int first;
    int second;
};

int sum_intervals(const struct interval *v, size_t n)
{
    struct interval aux;
    struct interval *temp;
    int             start = 0;
    int             end = 0;
    int             total = 0;
    size_t          i = 0;

    temp = malloc(n * sizeof(struct interval));
    memcpy(temp, v, n * sizeof(struct interval));
    while (i < n)
    {
        if (temp[i + 1].first < temp[i].first && (i + 1) < n)
        {
            aux = temp[i + 1];
            temp[i + 1] = temp[i];
            temp[i] = aux;
            i = 0;
        }
        else
            i++;
    }
    i = 0;
    start = temp[i].first;
    end = temp[i].second;
    i = 1;
    while (i < n)
    {
        if (temp[i].first < end)
        {
            if (temp[i].second > end)
                end = temp[i].second;
        }
        else
        {
            total += end - start;
            start = temp[i].first;
            end = temp[i].second;
        }
        i++;
    }
    total += end - start;
    free(temp);

    return (total);
}