#include <unistd.h>

int	ft_isdb(char *s1, char c, int pos)
{
	int	t;

	t = 0;
	while (t < pos)
	{
		if (s1[t] == c)
			return (1);
		t++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && ft_isdb(s1, s2[j], i) == 0)
			{
				write(1, &s1[i], 1);
				break;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
