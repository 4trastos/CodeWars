#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int find_diff(const int *arr1, const int *arr2, size_t n1, size_t n2, int *str)
{
    size_t i = 0;
    size_t x = 0;
    int diff = 0;
    int z = 0;
    int flag = 0;

    while (i < n1)
    {
        x = 0;
        flag = 0;
        while (x < n2 && flag == 0)
        {
            if (arr1[i] == arr2[x])
                flag = 1;
            x++;
        }
        if (flag == 0)
        {
            if (str != NULL)
            {
                str[z] = arr1[i];
                z++;
            }
            diff++;
        }
        i++;
    }
    return (diff);
}

int *array_diff(const int arr1[/* n1 */], size_t n1, const int arr2[/* n2 */], size_t n2, size_t *z)
{
    int *expected;
    int diff = 0;

    diff = find_diff(arr1, arr2, n1, n2, NULL);
    expected = malloc(diff * sizeof(int));
    if (!expected)
        return (NULL);
    *z = (size_t)diff;
    diff = find_diff(arr1, arr2, n1, n2, expected);
    
    return (expected);
}

int main(void)
{
    const int arr1[3] = {1, 2, 2};
    const int *arr2 = NULL;
    const int *expected;
    size_t z = 0;

    expected = array_diff(arr1, 3, arr2, 0, &z);

    printf("Expected: (%ls)\n", expected);
    return (0);
}