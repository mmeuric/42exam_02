#include <unistd.h>

int	ft_db2(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;	
	}
	return (0);
}

int	ft_db1(char *str, char c, int pos)
{
	int 	t;

	t = 0;
	while (t < pos)
	{
		if (str[t] == c)
			return (1);
		t++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_db1(s1, s1[i], i) == 0)
		{
			write(1, &s1[i], 1);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (ft_db2(s1, s2[i]) == 0)
		{
			if (ft_db1(s2, s2[i], i) == 0)
				write (1, &s2[i], 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);		
	}
	write(1, "\n",1);
	return (0);
}
