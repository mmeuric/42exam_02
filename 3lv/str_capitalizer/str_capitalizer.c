#include <unistd.h>

char	*ft_lowcase(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

void	ft_strcap(char *str)
{
	int i = 0;
	int boul = 1;

	ft_lowcase(str);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			boul = 1;	
		}
		else if (str[i] >= 32 && str[i] <= 126 && boul == 1)
		{
			str[i] -= 32;
			boul = 0;
		}
		write(1, &str[i], 1);
		i++;
	}

}

int	main(int ac, char **av)
{
	int i = 1;
	
	if (ac > 1)
	{
	while (i < ac)	
	{
		ft_strcap(av[i]);
		write(1, "\n", 1);		
		i++;
	}
	}
	else 
		write(1, "\n", 1);
	return 0;
}
