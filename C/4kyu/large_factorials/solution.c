#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *factorial(int n)
{
  char          *str;
  int           digits[3000];
  int           size = 1;
  int           num = 2;
  int           carry = 0;
  int           result = 0;
  int           i = 0;

  if (n < 0)
    return ("");
  
  if ( n == 0 || n == 1)
  {
    str = malloc(sizeof(char) * 2);
    if (!str)
      return (NULL);
    str[0] = '1';
    str[1] = '\0';
    return (str);
  }

  digits[0] = 1;

  while (num <= n)
  {
    carry = 0;
    i = 0;
    while (i < size)
    {
      result = digits[i] * num + carry;
      digits[i] = result % 10;
      carry = result / 10;
      i++;
    }
    while (carry > 0)
    {
      digits[size] = carry % 10;
      carry = carry / 10;
      size++;
    }
    num++;
  }
  
  str = malloc(sizeof(char) * (size + 1));
  if (!str)
    return (NULL);
  str[size] = '\0';

  i = 0;
  while (i < size)
  {
    str[size - 1 - i] = '0' + digits[i];
    i++;
  }
  
  return (str);
}

// int main()
// {
//   printf("( %s )\n", factorial(15));
//   return (0);
// }