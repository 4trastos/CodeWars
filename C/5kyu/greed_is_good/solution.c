#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>

int score(const int dice[5])
{
    int i = 0;
    int result = 0;
    int count[7] = {0, 0, 0, 0, 0, 0, 0};
    
    while (i < 5)
    {
        count[dice[i]]++; 
        i++;
    }
    if (count[1] >= 3)
        result += 1000;
    if (count[1] % 3 != 0)
        result += (count[1] % 3) * 100;
    if (count[2] >= 3)
        result += 200;
    if (count[3] >= 3)
        result += 300;
    if (count[4] >= 3)
        result += 400;
    if (count[5] >= 3)
        result += 500;
    if (count[5] % 3 != 0)
        result += (count[5] % 3) * 50;
    if (count[6] >= 3)
        result += 600;
    
    return (result);
}