#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define COUNTS_SIZE 128

void    count(const char *string, unsigned counts[COUNTS_SIZE])
{
    int     i = 0;
    memset(counts, 0, COUNTS_SIZE * sizeof(unsigned));

    while (string[i] != '\0')
    {
        counts[(int)string[i]]++;
        i++;
    }
    return;
}

int main(void)
{
    unsigned counts[COUNTS_SIZE];

    count("aba", counts);
    return (0);
}