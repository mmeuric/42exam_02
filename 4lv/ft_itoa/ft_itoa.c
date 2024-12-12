#include <stdlib.h>
#include <stdio.h>

int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*tab;
	long	n;
	int	len;

	n = nbr;
	len = ft_len(n);
	tab = malloc(sizeof(char) * ( len + 1));
	if (!tab)
		return (NULL);
	tab[len] = '\0';
	if (nbr == 0)
	{
		tab[0] = '0';
		return (tab);
	}
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		if (tab[len] == '-')
			break ;
		tab[len - 1] = (n % 10) + 48;
		len--;
		n /= 10;	
	}
	return (tab);
}

int	main(void)
{
	char	*tab;

	tab = ft_itoa(1234);
	printf("1234 = %s\n\n", tab);
	free(tab);

	tab = ft_itoa(-1234);
        printf("-1234 = %s\n\n", tab);
        free(tab);

	return (0);
}
