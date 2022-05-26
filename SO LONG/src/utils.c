#include "solong.h"

void recursive(int number, int *index, char *str)
{
	if (number)
	{
		recursive(number / 10, index, str);
		str[(*index)] = (number % 10) + 48;
		(*index)++;
		str[(*index)] = '\0';
	}
}

char *make_number(int number)
{
	char *str;
	int tmp;
	int len;

	tmp = number;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	len = 0;
	recursive(number, &len, str);
	return (str);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}