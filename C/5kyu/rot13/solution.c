#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

char    ft_rotation(char c)
{
    int     i = 0;
    char    z;
    char    *lower = "abcdefghijklmnopqrstuvwxyz";
    char    *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (c >= 'a' && c <= 'z')
    {
        while (lower[i] != '\0')
        {
            if (c == lower[i])
            {
                z = lower[(i + 13) % 26];
                return (z);
            }
            i++;
        }
    }
    else if (c >= 'A' && c <= 'Z')
    {
        while (upper[i] != '\0')
        {
            if (c == upper[i])
            {
                z = upper[(i + 13) % 26];
                return (z);
            }
            i++;
        }
    }
    return (c);
}

char *rot13(char *str_out, const char *str_in)
{
    int     i = 0;

    *str_out = '\0';

    if (!str_in || strlen(str_in) == 0)
        return (str_out);

    while (str_in[i]!= '\0')
    {
        str_out[i] = ft_rotation(str_in[i]);
        i++;
    }
    str_out[i] = '\0';
    
    return (str_out);
}

// int main()
// {
//     char str_out[100];
//     printf("%s Ordenado -> %s Mio -> %s\n", "EBG13 rknzcyr.", "ROT13 example.", rot13(str_out, "EBG13 rknzcyr."));
//     printf("%s Ordenado -> %s Mio -> %s\n", "Guvf vf zl svefg EBG13 rkprepvfr!", "This is my first ROT13 excercise!", rot13(str_out, "Guvf vf zl svefg EBG13 rkprepvfr!"));
//     return (0);
// }