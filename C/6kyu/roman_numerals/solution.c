#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    ft_printfdigits(int *digits, int len)
{
    int i = 0;
    printf("Contenido del array: ");
    while (i < len)
    {
        printf(" %d, ", digits[i]);
        i++;
    }
    printf("\n");
    
}

void    ft_interpretation(int *digits, const char *romans)
{
    int i = 0;

    while (romans[i] != '\0')
    {
        if (romans[i] == 'I')
            digits[i] = 1;
        else if (romans[i] == 'V')
            digits[i] = 5;
        else if (romans[i] == 'X')
            digits[i] = 10;
        else if (romans[i] == 'L')
            digits[i] = 50;
        else if (romans[i] == 'C')
            digits[i] = 100;
        else if (romans[i] == 'D')
            digits[i] = 500;
        else
            digits[i] = 1000;
        i++;
    }
}

unsigned    decode_roman (const char *roman_number)
{
    int i = 0;
    int len = strlen(roman_number);
    int calculate[1024] = {0};
    int x = 0;
    int y = 0;
    int result = 0;

    ft_interpretation(calculate, roman_number);
    ft_printfdigits(calculate, len);

    result = calculate[i];
    if (len == 1)
        return (result);

    while (i < len)
    {
        x = calculate[i]; 
        y = calculate[i + 1];
        if (x < y)
            result = result + y - 2 * x;
        else
            result = result + y;
        i++;
    }

	return (result);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    printf("%d\n", decode_roman(argv[1]));

    return (0);
}