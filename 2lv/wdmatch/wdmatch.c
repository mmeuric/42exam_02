#include <unistd.h>

int	ft_wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (s1[i])
	{	
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (count);	
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{	
	int	count;
	int	len;

	if (ac == 3)
	{
		count = ft_wdmatch(av[1], av[2]);
		len = 0;
		while (av[1][len])
			len++;
		if (len == count)
			ft_putstr(av[1]);
	}
	write(1,"\n", 1);
	return (0);
}
