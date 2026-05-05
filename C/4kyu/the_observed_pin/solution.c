#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char  *neighbors[] = {
    "08",    // Índice 0
    "124",   // Índice 1
    "1235",  // Índice 2
    "236",   // Índice 3
    "1457",  // Índice 4
    "24568", // Índice 5
    "3569",  // Índice 6
    "478",   // Índice 7
    "57890", // Índice 8
    "689"    // Índice 9
};

void    ft_copycomb(const char *observed, int pos, char *buffer, char **result, size_t *row)
{
    const char *options;
    int digit = 0;
    int i = 0;

    if (observed[pos] == '\0')
    {
        result[*row] = malloc(strlen(buffer) + 1);
        if (result[*row])
            strcpy(result[*row], buffer);
        (*row)++;
        return;
    }

    digit = observed[pos] - '0';
    options = neighbors[digit];
    while (options[i] != '\0')
    {
        buffer[pos] = options[i];
        ft_copycomb(observed, pos + 1, buffer, result, row);
        i++;
    }
}

void    ft_combinations(const char *str, size_t *count)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '1' || str[i] == '3' || str[i] == '7' || str[i] == '9')
            *count *= 3;
        else if (str[i] == '0')
            *count *= 2;
        else if (str[i] == '2'|| str[i] == '4' || str[i] == '6')
            *count *= 4;
        else
            *count *= 5; 
        i++;
    }   
}


const char** get_pins(const char* observed, size_t* count)
{
    char    **str;
    char    buffer[9];
    size_t  len = 0;
    size_t  size = 0;
    size_t  row = 0;
    
    *count = 1;
    size = strlen(observed);
    ft_combinations(observed, count);

    len = *count;
    buffer[size] = '\0';
    str = malloc(sizeof(char *) * (len + 1));
    if (!str)
        return (NULL);
    ft_copycomb(observed, 0, buffer, str, &row);

    str[*count] = NULL;
    return ((const char **)str);
}

//This function will be called once per every call to get_pins
//with a pointer value returned by such call.
void free_pins(const char ** pins)
{
    int     i = 0;

    if (!pins)
        return;
    
    while (pins[i])
    {
        free((void *)pins[i]);
        i++;
    }
    free((void *)pins);
}