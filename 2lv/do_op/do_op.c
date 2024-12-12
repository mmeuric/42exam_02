#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac == 4)
	{
		i = 0;
		if (av[2][i] == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		if (av[2][i] == '*')
                        printf("%d", atoi(av[1]) * atoi(av[3]));
		if (av[2][i] == '-')
                        printf("%d", atoi(av[1]) - atoi(av[3]));
		if (av[2][i] == '/')
                        printf("%d", atoi(av[1]) / atoi(av[3]));
		if (av[2][i] == '%')
                        printf("%d", atoi(av[1]) % atoi(av[3]));
	}
	printf("\n");
	return (0);
}
