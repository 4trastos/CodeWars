#include <stdint.h>

uint64_t ft_minumun(uint64_t next2, uint64_t next3, uint64_t next5)
{
    uint64_t min = 0;

    if (next3 < next2)
        min = next3;
    else
        min = next2;
    
    if (min < next5)
        return(min);
    else
        return(next5);
}

uint64_t    hamber(int n)
{
    uint64_t hamming[n];
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    int x = 1;
    uint64_t next2, next3, next5;

    hamming[0] = 1;
    next2 = 0;
    next3 = 0;
    next5 = 0;
    while (x < n)
    {
        next2 = hamming[i2] * 2;
        next3 = hamming[i3] * 3;
        next5 = hamming[i5] * 5;

        hamming[x] = ft_minumun(next2, next3, next5);
        if (hamming[x] == next2)
            i2++;
        if (hamming[x] == next3)
            i3++;
        if  (hamming[x] == next5)           
            i5++;
        x++;
    }
    
    return (hamming[n -1]);
}