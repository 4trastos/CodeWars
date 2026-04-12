#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int ft_compare(const void *a, const void *b)
{
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return(strcmp(s1, s2));
}

const char **inArray(const char *const array1[/* sz1 */], int sz1, const char *const array2[/* sz2 */], int sz2, int *lg)
{
    const char **aux;
    int x, y;
    *lg = 0;

    if (!array2 || sz2 == 0 || !array1 || sz1 == 0)
        return (NULL);
    
    aux = malloc(sizeof (char *) * (sz1 + 1));
    if (!aux)
        return (NULL);
    
    x = 0;
    while (x < sz1)
    {
        y = 0;
        while (y < sz2)
        {
            if (strstr(array2[y], array1[x]) != NULL)
            {
                aux[*lg] = array1[x];
                (*lg)++;
                break;
            }
            y++;
        }
        x++;
    }
    aux[*lg] = NULL;
    qsort(aux, *lg, sizeof(char *), ft_compare);
    return (aux);
}

int main(void)
{
    const char **expected;
    const char *arr1[] = { "arp", "live", "strong" };
    const char *arr2[] = { "lively", "alive", "harp", "sharp", "armstrong" };
    int sz1 = 3;
    int sz2 = 5;
    int lg = 0;
    int i = 0;

    expected = malloc(sizeof(char *) * sz1 + 1);
    if (!expected)
        return (1);
    
    expected = inArray(arr1, sz1, arr2, sz2, &lg);

    while (i < lg)
    {
        printf("Encontrado: %s\n", expected[i]);
        i++;
    }

    printf("Longitud de la array experado: ( %d )\n", lg);

    return (0);
}