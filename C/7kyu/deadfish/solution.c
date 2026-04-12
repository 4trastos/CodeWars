#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

int find_letter(const char *str)
{
    int x = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'o')
            x++;
    }    
    return (x);
}

int *parse (const char *program)
{
    int *result;
    int i = 0;
    int x = 0;
    int z = 0;

    result = malloc(find_letter(program) * sizeof(int));
    if (!result)
        return (NULL);
    if (find_letter(program) == 0)
        return (NULL);

    while (program[i] != '\0')
    {
        if (program[i] == 'i')
            x = x + 1;
        else if (program[i] == 'd')
            x = x - 1;
        else if (program[i] == 's')
            x = x * x;
        else if (program[i] == 'o')
        {
            result[z] = x;
            z++;
        }
        i++;
    }
	return (result);
}

int main(int argc, char **argv)
{
    const char *str;

    if (argc != 2)
        return (1);
    
    str = argv[1];
    printf("Return Numbers: %ls\n", parse(str));
    return (0);
}