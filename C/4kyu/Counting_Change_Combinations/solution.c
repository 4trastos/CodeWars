#include <stdio.h>

int count_change(int money, int n_coins, const int coins[n_coins])
{
    //int current = 0;
    int total = 0;
    int comb = 0;
    int flag = 0;
    int z = 0;
    
    for (int i = 0; i < n_coins; i++)
        total += coins[i];
    if (total == money)
        comb++;
    total = 0;

    while (z < n_coins)
    {
        while (total <= money && flag == 0)
        {
            total = total + coins[z];
            if (total == money)
            {
                comb++;
                total = 0;
                flag = 1;
            }
        }
        if (total > money)
            total = total - coins[z];
        flag = 0;
        z++;
    }
    return (comb);
}