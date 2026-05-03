#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

long long ft_numlen(long long numbr)
{
    long long i = 0;
    while (numbr != 0)
    {
        numbr = numbr / 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(long long result, char *str)
{
    char        *new;
    long long   len = 0;
    long long   numb = result;

    len = ft_numlen(result);
    new = malloc((len + 1) * sizeof(char));
    if (!new)
        return (NULL);
    new[len] = '\0';
    while (numb != 0)
    {
        new[len - 1] = '0' + (numb % 10);
        numb = numb / 10;
        len--;
    }
    str = strcat(str, new);
    free(new);
    return (str);
}

void    ft_sortstr(long long *strnum, char *str, long long total)
{
    long long len = total - 1;
    while (len >= 0)
    {
        ft_itoa(strnum[len], str);
        if (len > 0)
            strcat(str, ",");
        len--;
    }
    
    return;
}

bool ft_decompsetwo(long long result, long long numb, long long *strnum, long long i, long long *total)
{
    if (result == 0)
    {
        *total = i;
        return (true);
    }

    while (numb > 0)
    {
        if (numb * numb <= result)
        {
            strnum[i] = numb;
            if (ft_decompsetwo(result - (numb * numb), numb - 1, strnum, i + 1, total) == true)
                return (true);
        }
        numb--;
    }
    return (false);
}

char *decompose(long long n)
{
    char        *str;
    long long   *strnum;
    long long   total = 0;
    long long   squar = n * n;
    long long str_size = 0;

    str_size = (n < 100) ? 1000 : (n * 25);
    str = malloc(str_size * sizeof(char));
    if (!str)
        return (NULL);

    str[0] = '['; str[1] = '\0';
    
    strnum = malloc(n * sizeof(long long));
    if (!strnum)
        return (NULL);

    if (ft_decompsetwo(squar, n - 1, strnum, 0, &total) == true)
    {
        ft_sortstr(strnum, str, total);
        free(strnum);
        str = strcat(str, "]");
    }
    else
    {
        free(strnum);
        free(str);
        return (strdup("[]"));
    }
    return (str);
}

/* int main()
{
    char *res = decompose(2);
    printf("Resultado para 2: %s\n", res);
    free(res);
    return 0;
} */
