#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *maskify (char *masked, const char *string)
{
    int i = 0;
    int end = 0;

    if (!string || (string[0] == '\0' && strlen(string) == 0))
    {
        masked[0] = '\0';
        return (masked);
    }
    end = strlen(string);
    masked[end] = '\0';
    end--;

    while (end >= 0)
    {
        if (i < 4)
        {
            masked[end] = string[end];
            end--;
            i++;
        }
        else
        {
            masked[end] = '#';
            end--;
        }
    }
    
	return (masked);
}

/* int main(int argc, char **argv)
{
    char    *masked;

    if (argc != 2)
        return (-1);
    
    masked = malloc(strlen(argv[1]) + 1);
    if (!masked)
        return (-1);
    
    //masked = maskify(masked, argv[1]);
    printf("%s\n", maskify(masked, argv[1]));
    
    return (0);   
} */