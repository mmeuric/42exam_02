#include <unistd.h>

void	ft_rot(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'y')
			str[i] += 1;
		else if (str[i] == 'z')
			str[i] -= 25;
		if (str[i] >= 'A' && str[i] <= 'Y')
                        str[i] += 1;
                else if (str[i] == 'Z')
                        str[i] -= 25;
		write(1, &str[i],1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_rot(av[1]);
	}
	write(1,"\n", 1);
	return (0);
}