#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res = 0;
	while (*str)
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb %= 10;
	nb += 48;
	write(1,&nb,1);
}


int	main(int ac, char **av)
{
	int	nb;
	int	mult;
	int	res;

	if (ac == 2 && av[1][0] != '-' && av[1][0] != '0' && ft_atoi(av[1]) <= 238609294)
	{
		nb = ft_atoi(av[1]);
		mult = 1;
		while (mult < 10)
		{
			ft_putnbr(mult);;
			write(1," ",1);
			write(1,"x",1);
			write(1," ",1);
			ft_putnbr(nb);
			write(1," ",1);
			write(1,"=",1);
			write(1," ",1);
			res = mult * nb;
			ft_putnbr(res);
			if (mult >= 1 && mult <= 8)
				write(1,"\n",1);
			mult++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
