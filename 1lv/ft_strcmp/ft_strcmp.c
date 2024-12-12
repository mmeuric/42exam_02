#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac == 3)
	{
		res = ft_strcmp(av[1], av[2]);
		printf("Voici : %d\n", res);
	}
	return (0);
}
