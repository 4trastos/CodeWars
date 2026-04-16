#include <stddef.h>

double  mean_square_error(size_t n, const int a[n], const int b[n])
{
    double  result = 0;
    double  operat[n];

    for (size_t i = 0; i < n; i++)
    {
        operat[i] = (a[i] - b[i]);
        operat[i] *= operat[i];
    }    
    
    for (size_t i = 0; i < n; i++)
        result += operat[i];
    result /= n;
    
    return (result);
}