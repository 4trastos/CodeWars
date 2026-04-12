#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


bool isValidWalk(const char *walk)
{
    int i = 0;
    int x = 0;
    int y = 0;

    if (strlen(walk) != 10)
        return (false);

    while (walk[i] != '\0')
    {
        if (walk[i] == 'n')
            y++;
        else if (walk[i] == 's')
            y--;
        else if (walk[i] == 'w')
            x--;
        else
            x++;
        i++;
    }
    
    if (x == 0 && y == 0)
        return (true);
    return (false);
}

int main(int argc, char **argv)
{
    const char *walk;

    if (argc != 2)
        return (-1);

    walk = (const char*)argv[1];
    if (isValidWalk(walk))
        return (printf("True\n"));
    else
        return (printf("False\n"));
    return (0);
}