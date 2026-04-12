#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int ft_utf8_length(unsigned char c)
{
    if ((c & 0x80) == 0)
        return (1);
    else if ((c & 0xE0) == 0xC0)
        return (2);
    else if ((c & 0xF0) == 0xE0)
        return (3);
    else if ((c & 0xF8) == 0xF0)
        return (4);
    else
        return (1);
}


void first_non_repeating_codepoint(char output[4 + 1], const char *utf8)
{
    unsigned    c;
    int         size_i, size_x, i, x, y;

    i = 0;
    while (utf8[i] != '\0')
    {
        c = utf8[i];
        size_i = ft_utf8_length(c);
        x = 0;
        y = 0;
        while (utf8[x] != '\0')
        {
            size_x = ft_utf8_length(utf8[x]);
            if (size_i == size_x)
            {
                if (size_i == 1)
                {
                    if (tolower((unsigned char)utf8[i]) == tolower((unsigned char)utf8[x]))
                        y++;
                }
                else
                {
                    if (strncmp(&utf8[i], &utf8[x], size_i) == 0)
                        y++;
                }
            }
            x += size_x;
        }
        if (y == 1)
        {
            strncpy(output, &utf8[i], size_i);
            output[size_i] = '\0';
            return;
        } 
        i += size_i;
    }
    *output = '\0';
    return;
}

int main(int argc, char **argv)
{
    char output[6];
    if (argc != 2)
        return (1);
    
    first_non_repeating_codepoint(output, argv[1]);

    return (0);
}