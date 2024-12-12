#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else 
		return (n);
}

int     *ft_range(int start, int end)
{
	int	size;
	int	i;
	int	*tab;

	size = ft_abs(end - start) + 1; 
	i = 0;
	tab = malloc(sizeof(int *) * size);
	if (size == 0)
	{
		tab[0] = 0;
		return (tab);
	}
	if (end > start)
	{
		while (i < size)
		{
			tab[i] = start + i;
			i++;
		}	
	}
	i = 0;
	if (end < start)
	{
		while (i < size)
		{
			tab[i] = start - i;
			i++;
		}
	}
	return (tab);
}
/*
int	main(void)
{
	int	*tab;
	int	i;
	int	size;

	int start = 1;
	int end = 3;
	size = ft_abs(end - start) + 1;
	i = 0;
	tab = ft_range(start, end);
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
