# include <stdlib.h>
# include <string.h>

typedef struct s_numbers_entry
{
    const char      *word;
    long            value;
} t_numbers_entry;

t_numbers_entry g_units[] =
{
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
    {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"and", 0}
};

t_numbers_entry g_tens[] =
{
    {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
    {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

t_numbers_entry g_scales[] =
{
    {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
};

long    ft_parser(const char *number)
{
    int     i = 0;
    int     x = 0;
    int     z = 0;
    long    total = 0;
    long    current = 0;
    char    *aux;

    aux = malloc(strlen(number) +1 );
    while(number[i] != '\0')
    {
        x = 0;
        while (number[i] != ' ' && number[i] != '\0' && number[i])
        {
            if (number[i] == '-')
            {
                i++;
                break;
            }
            else
            {
                aux[x] = number[i];
                i++;
                x++;
            }
        }
        aux[x] = '\0';
        z = 0;
        while (z < 20)
        {
            if (strcmp(g_units[z].word, aux) == 0)
                current = current + g_units[z].value;
            z++;
        }
         
        z = 0;
        while (z < 8)
        {
            if (strcmp(g_tens[z].word, aux) == 0)
                current = current + g_tens[z].value;
            z++;
        }

        z = 0;
        while (z < 3)
        {
            if (strcmp(g_scales[z].word, aux) == 0)
            {
                if (strcmp(g_scales[z].word, "thousand") == 0)
                {
                    total = total + (current * 1000);
                    current = 0;
                }
                else if (strcmp(g_scales[z].word, "million") == 0)
                {
                    total = total + (current * 1000000);
                    current = 0;
                }
                else
                    current = current * g_scales[z].value;
            }    
            z++;
        }
        if (number[i] == ' ' && number[i + 1] != '\0')
            i++;
    }
    free(aux);
    return (total + current);
}

long parse_int (const char* number)
{
    long result = 0;

    result = ft_parser(number);
    return (result);
}