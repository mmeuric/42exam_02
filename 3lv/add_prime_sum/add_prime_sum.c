#include <unistd.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;	
	}
	return (nb);
}

int	ft_isprime(int nb)
{
	int	i;
	
	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int nb)
{
	if (nb > 9)
		put_nbr(nb / 10);
	nb %= 10;
	nb += 48;
	write(1, &nb,1);
}

int	main(int ac, char **av)
{
	int	nb;
	int	res;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		res = 0;
		while (nb > 0)
		{
			if (ft_isprime(nb) == 1)
				res += nb;
			nb--;
		}
		put_nbr(res);	
	}
	if (ac != 2)
		put_nbr(0);
	write(1, "\n",1);
	return (0);
}
