#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

char    *ft_strdup(char *dst)
{
    char    *new;
    int     i = 0;

    new = malloc(strlen(dst) + 1);
    if (!new)
        return (NULL);
    while (dst[i] != '\0')
    {
        new[i] = dst[i];
        i++;
    }    
    new[i] = '\0';
    free (dst);
    return (new);
}

char    *ft_strcat(char *dst, char *src)
{
    char    *aux;
    int     i = 0;
    int     j = 0;

    if (!dst)
    {
        dst = malloc(strlen(src) + 1);
        if (!dst)
            return (NULL);
        while (src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }    
        dst[i] = '\0';
        return (dst);
    }

    aux = malloc(strlen(dst) + strlen(src) + 2);
    if (!aux)
        return (NULL);
    while (dst[i] != '\0')
    {
        aux[i] = dst[i];
        i++;
    }    
    aux[i] = ' ';
    i++;
    while (src[j] != '\0')
    {
        aux[i] = src[j];
        i++;
        j++;
    }    
        
    aux[i] = '\0';
    free(dst);
    return (aux);
}

int ft_compare(const void *a, const void *b)
{
    int weight_a = 0;
    int weight_b = 0;

    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;

    for (int i = 0; s1[i] != '\0'; i++)
        weight_a += s1[i] - '0';
    for (int i = 0; s2[i] != '\0'; i++)
        weight_b += s2[i] - '0';

    if (weight_a == weight_b)
        return(strcmp(s1, s2)); 
    else
        return (weight_a - weight_b);
}

char    *split_tokens(const char *str, char c, int *pointer)
{
    char        *new;
    int         len = 0;
    int         i = 0;

    while (str[*pointer] == c)
        (*pointer)++;
    while ((str[*pointer + len] != c) && str[*pointer + len])
        len++;
    new = malloc((size_t)len * sizeof(char) + 1);
    if (!new)
        return (NULL);
    while ((str[*pointer] != c) && str[*pointer])
        new[i++] = str[(*pointer)++];
    new[i] = '\0';
    return (new);
}

int  token_acount(const char *str)
{
    int     tokens = 0;
    int     i = 0;
    char    c = ' ';

    while (str[i] != '\0')
    {
        if (str[i] != c && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            tokens++;
        i++;
    }  
    return (tokens);
}

char *orderWeight(const char *string)
{
    char    **tokens;
    char    *sort = NULL;
    char    *aux;
    int     amount;
    int     pointer = 0;
    int     i = 0;

    amount = token_acount(string);
    if (amount == 0)
        return (NULL);
    
    tokens = malloc(sizeof(char*) * (amount + 1));
    if (!tokens)
        return (NULL);
    for (i = 0; i < amount; i++)
        tokens[i] = split_tokens(string, ' ', &pointer);
    tokens[i] = NULL;

    qsort(tokens, amount, sizeof(char *), ft_compare);
    i = 0;
    while (tokens[i] != NULL)
    {
        aux = ft_strcat(sort, tokens[i]);
        sort = ft_strdup(aux);
        i++;
    }
    return (sort);
}

int main(int argc, char **argv)
{
    const char *str;

    if (argc != 2)
        return (1);

    str = argv[1];
    printf("Números a ordenar: (%s)\n", str);
    str = orderWeight(str);
    printf("String ordenado:   (%s)\n", str);
    
    return (0);
}