#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res);
}

void	ft_printhex(int nb)
{
	static const char *hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_printhex(nb / 16);
	write(1, &hex[nb % 16], 1);
}

int	main(int ac, char **av)
{
	int	nb;
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		ft_printhex(nb);
	}
	write(1, "\n", 1);
	return (0);
}
