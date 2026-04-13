#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void    ft_copy_word(char *dst, const char *src, int start, int end)
{
    int i = 0;

    while (start <= end)
    {
        dst[i] = src[start];
        start++;
        i++;
    }
    dst[i] = '\0';
}

void    ft_double_free(char **str)
{
    int i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void    ft_ordered_words(char **aux, const char *words, char c, int amount)
{
    char    *support;
    int     i = 0;
    int     start = 0;
    int     end = 0;
    int     x = 0;
    int     j = 0;
    int     change = 0;

    while (words[i] != '\0' && x < amount)
    {
        if (words[i] != c)
        {
            start = i;
            while (words[i] != c && words[i] != '\0')
                i++;
            end = i - 1;
            aux[x] = malloc((end - start) + 1);
            ft_copy_word(aux[x], words, start, end);
            x++;
        }
        i++;
    }
    aux[x] = NULL;
    
    x = 0;
    while (aux[x] != NULL)
    {
        change = 0;
        i = 0;
        while (aux[x][i] != '\0' && change == 0 && x != (amount - 1))
        {
            if (aux[x][i] >= '1' && aux[x][i] <= '9')
            {
                start = aux[x][i];
                while (aux[x + 1][j] != '\0' && aux[x + 1] != NULL)
                {
                    if (aux[x + 1][j] >= '1' && aux[x + 1][j] <= '9')
                        end = aux[x + 1][j];
                    j++;
                }
                if (start > end)
                {
                    support = aux[x + 1];
                    aux[x + 1] = aux[x];
                    aux[x] = support;
                    change = 1;
                }
                start = 0;
                end = 0;
                j = 0;
            }
            i++;
        }
        if (change == 1)
            x = 0;
        else
            x++;
    }
}

void    ft_count_words(const char *words, char c, int *amount)
{
    int i = 0;

    while (words[i] != '\0')
    {
        if (words[i] != c && (words[i + 1]  == '\0' || words[i + 1] == c))
            (*amount)++;
        i++;
    }
}

char *order_words (char *ordered, const char *words)
{
    char    **aux;
    int     amount = 0;
    int     i = 0;

    *ordered = '\0';
    if (!words || words[0] == '\0')
    return (ordered);
    
    ft_count_words(words, ' ', &amount);
    aux = malloc(sizeof(char *) * (amount + 1));
    if (!aux)
        return (ordered);
    ft_ordered_words(aux, words, ' ', amount);
    while (i < amount)
    {
        strcat(ordered, aux[i]);
        if (i != amount - 1)
            strcat(ordered, " ");
        i++;
    }
    ft_double_free(aux);
	return (ordered);
}

/* int main(void)
{
    char ordered[1024];
    printf("String Sin ordendar: %s\n", "is2 Thi1s T4est 3a");
    printf("String ordendado: %s\n", order_words(ordered, "is2 Thi1s T4est 3a"));
    return (0);
} */