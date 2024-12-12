#include <stdio.h>

int		max(int *tab, unsigned int len)
{
	int	res;
	int	i;

	if (len == 0)
		return (0);
	i = 0;
	res = tab[0];
	while (i < len)
	{
		if (res < tab[i])
			res = tab[i];
		i++;
	}
	return (res);
}

int	main(void)
{
	int	tab[] = {2, 5, 4, 8, 6, 7};

	printf("%d\n", max(tab, 6));
	return (0);
}
