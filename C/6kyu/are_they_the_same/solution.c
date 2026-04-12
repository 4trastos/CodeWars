#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// void    printArray(size_t n, int array[/* n */])
// {
//     printf("{");
//     for (size_t i = 0; i < n; i++)
//         printf("%d%s", array[i], (i == n - 1) ? "" : ", ");
//     printf("}\n");
// }

void    ft_sort(int *str, size_t n)
{
    size_t i = 0;
    int     aux;
    while (i < n - 1)
    {
        if (str[i] < str[i + 1])
        {
            aux = str[i];
            str[i] = str[i + 1];
            str[i + 1] = aux;
            i = 0;
        }
        else
            i++;
    }
}

bool comp(const int a[/*n*/], const int b[/*n*/], size_t n)
{
    size_t i = 0;
    int *a_sort;
    int *b_sort;

    if (!a || !b)
        return (false);
    
    a_sort = malloc(n * sizeof(int));
    if (!a_sort)
        return (false);
    b_sort = malloc(n * sizeof(int));
    if (!b_sort)
        return (false);
    a_sort[0] = 0;
    b_sort[0] = 0;

    while (i < n)
    {
        b_sort[i] = b[i];
        a_sort[i] = a[i];
        a_sort[i] = (a_sort[i] * a_sort[i]);
        i++;
    }
    // printf("Sin ordenar ---> ");
    // printArray(n, a_sort);
    // printArray(n, b_sort);
    ft_sort(a_sort, n);
    ft_sort(b_sort, n);
    // printf("Ordenada ---> ");
    // printArray(n, a_sort);
    // printArray(n, b_sort);
    i = 0;
    while (i < n)
    {
        if (a_sort[i] != b_sort[i])
        {
            free(a_sort);
            free(b_sort);
            return (false);
        }
        i++;
    }
    free(a_sort);
    free(b_sort);
    return (true);
}

// int main (void)
// {
//     const int a[] = {0, 0, -2, -1, 0};
//     const int b[] = {0, 0, 2, -3, 0};
//     printf("Test 7: %d (esperado 0)\n", comp(a, b, 5));
//     return(0);
// }