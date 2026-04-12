#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_binary(unsigned long long octet, char *binary)
{
    int i = 33;
    int x = 0;
    char aux[35];

    while (i >= 0)
    {
        aux[33 - i] = ((octet >> i) & 1) + '0';
        i--;
    }
    aux[34] = '\0';
    if (octet == 0)
    {
        binary[0] = '0';
        binary[1] = '\0';
        return (binary);
    }

    i = 0;
    while (aux[i] == '0')
        i++;
    while (aux[i] != '\0')
        binary[x++] = aux[i++];
    
    binary[x] = '\0';
    return (binary);
}

char *binary_add (unsigned a, unsigned b, char *binary)
{
    unsigned long long add;
    add = (unsigned long long)a + b;
	return (ft_binary(add, binary));
}


int main(int argc, char **argv)
{
    char binary[34];
    unsigned a;
    unsigned b;

    if (argc != 3)
        return (1);

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%s\n", binary_add(a, b, binary));

    return (0);
}