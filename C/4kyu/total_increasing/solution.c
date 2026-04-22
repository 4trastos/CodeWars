#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

unsigned long long ft_combination(int x, int y)
{
    unsigned long long  result = 0;

    if (y > x - y)
        y = x - y;

    result = 1;
    for (int i = 1; i <= y; i++)
        result = result * (x - y + i) / i;
    
    return (result);
}

unsigned long long total_inc_dec(unsigned int n)
{
    unsigned long long x;
    unsigned long long y; 
    
    if (n == 0)
        return (1);
    
    x = ft_combination(n + 10, 10);
    y = ft_combination(n + 9, 9);

    return (x + y - 1 - (10ULL * n));
}
