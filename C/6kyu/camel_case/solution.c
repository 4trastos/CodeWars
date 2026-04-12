#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_textlen(char *str)
{
	int len = 0;
	int i = 0;

	while (str[len] != '\0')
	{
		if (str[len] == '-' || str[len] == '_')
			i++;
		len++;
	}
	
	return (len - i);
}

void to_camel_case(const char *text, char *camel)
{
	int i = 0;
	int x = 0;
	int flag = 0;

	if (!text || text[i] == '\0')
	{
		camel[x] = '\0';
		return;
	}

	if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
	{
		camel[x] = text[i];
		x++;
	}	
		
	i++;
	while(text[i] != '\0')
	{
		flag = 0;
		while ((text[i] == '-' || text[i] == '_') && text[i] != '\0')
		{
			flag = 1;
			i++;
		}
		if (text[i] != '\0')
		{
			if (flag == 1)
			{
				if (text[i] >= 'a' && text[i] <= 'z')
					camel[x] = text[i] - 32;
				else
					camel[x] = text[i];
	
			}
			else
				camel[x] = text[i];
			i++;
			x++;
		}
	}
	camel[x] = '\0';
	return;
}

int main (int argc, char **argv)
{
	const char *text;
	char *camel;
	int len;

	if (argc != 2)
		return (1);
	len = ft_textlen(argv[1]);
	text = (const char*)argv[1];
	camel = malloc(len+ 1);
	if (!camel)
		return (-1);

	to_camel_case(text, camel);

	write(1, camel, strlen(camel));
	write(1, "\n", 1);

	free(camel);

	return(0);
}
