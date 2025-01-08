#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	
	if (!s1 || !s2)
		return (0);
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;	
	}
	return (NULL);
}

int main(void)
{
    printf("Voici %s\n", ft_strpbrk("bonjour", "aeo"));
    printf("Voici %s\n", strpbrk("bonjour", "aeo"));
    return 0;
}