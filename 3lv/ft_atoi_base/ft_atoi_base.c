#include <stdio.h>


int	ft_atoi_base(const char *str, int str_base)
{
	int	res = 0;
	int	sign = 1;
	int	i = 0;
	int	c;
	
	if (str_base > 16 || str_base < 2)
		return (0);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			c = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
                        c = str[i] - 'A' + 10;
		else
			break ;
		if (c >= str_base)
			break ;
		res = res * str_base + c;
		i++;
	}
	return (res * sign);
}

int	main(void)
{
	int a = ft_atoi_base("0f", 16);
	printf("Voici : %d\n", a);
	return (0);
}
