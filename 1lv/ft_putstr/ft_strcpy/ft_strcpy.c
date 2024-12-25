#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{	
	char	*start;

	start = s1;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	s1 = start;
	return (s1);
}

int	main(void)
{
	char	a[50];
	char	b[50] = "Bonjour les amis !";
	
	printf("%s\n", ft_strcpy(a, b));

	return (0);
}
