#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

int     *ft_rrange(int start, int end)
{
	int	i;
	int	size;
	int	*tab;

	size = ft_abs(end - start) + 1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	if ((end - start) == 0)
	{
		tab[0] = start;
		return (tab);
	}
	i = 0;
	if ((end - start) > 0)
	{
	while (i < size)
	{
		tab[i] = end - i;		
		i++;
	}
	}
	i = 0;
	if ((end - start) < 0)
        {
        while (i < size)
        {
                tab[i] = end + i;  
                i++;
        }
        }
	return (tab);
}
/*
int	main(void)
{
	int	i = 0;
	int	*tab = NULL;
	int	start = 0;
	int	end = -3;
        int     size = ft_abs(end - start) + 1;

	tab = ft_rrange(start, end);
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
