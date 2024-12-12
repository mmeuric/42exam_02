#include <stdio.h>

char    *ft_strrev(char *str)
{
	int	i;
	int	len;
	char	stock;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	len--;
	while (i < len)
	{
		stock = str[i]; 
		str[i] = str[len];
		str[len] = stock;
		i++;
		len--;
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Avant : %s\n", av[1]);
		ft_strrev(av[1]);
		printf("Apres : %s", av[1]);
	}
	printf("\n");
	return 0;
}
