#include <stdlib.h>
#include <stdio.h>

int	ft_issep(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int	count_w(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i]) == 1)
			i++;
		if (str[i] && ft_issep(str[i]) == 0)
		{
			count++;
			while (str[i] && ft_issep(str[i]) == 0)
				i++;	
		}
	}	
	return (count);
}

void	ft_strcpy(char *tab, char *str, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab[i] = str[start + i];
		i++;
	}
	tab[len] = '\0';
}

void	ft_fill(char *str, char **tab, int nbw)
{
	int	i = 0;
	int	word = 0;
	int	count = 0;
	int	len = 0;
	int	start = 0;

	while (str[i])
	{	
		word = 0;
		len = 0;
		while (str[i] && ft_issep(str[i]) == 1)
			i++;
		start = i;
		while (str[i] && ft_issep(str[i]) == 0)
		{
			i++;
			len++;
			word = 1;
		}
		if (word == 1 && count < nbw)
		{
			tab[count] = malloc(sizeof(char) * (len + 1));
			ft_strcpy(tab[count], str, start, len);
			count++;
		}
	}
}
char    **ft_split(char *str)
{
	int	nbw;
	char	**tab;
	
	if (!str || *str == '\0')
		return (NULL);
	nbw = count_w(str);
	tab = malloc(sizeof(char *) * (nbw + 1));
	ft_fill(str, tab, nbw);
	tab[nbw] = NULL;
	return (tab);
}
/*
int	 main(void)
{
	char 	a[] = "Bo jo tout le \tmonde ca va ????";
	char	**tab;
	int	nbw;
	int 	i = 0;
	
	tab = ft_split(a);
	nbw = count_w(a);
	while (i <= nbw)
	{
		printf("[%s]\n", tab[i]);
		free(tab[i]);
		i++;
	}	
	free(tab);
	return (0);
}
*/
