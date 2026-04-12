#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int bouncingBall(double h, double bounce, double window)
{
    double  value = 0;
    int     count = 0;
    int     flag = 1;

    if (h <= 0 || window >= h || !(bounce > 0 && bounce < 1))
        return (-1);
    count++;
    while (flag)
    {
        value = h * bounce;
        h = value;
        if (value > window)
            count += 2;
        else
            flag = 0;
        continue;
    }
    return (count);
}

int main()
{
    double h = 10;
    double bounce = 0.59999999999999998;
    double window = 10;
    int result = 0;

    result = bouncingBall(h, bounce, window);
    printf("( %d )\n", result);

    return (0);
}
