#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
    int res = 0;

    while (*s1 && *s2 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    res = *s1 - *s2;
    if (res > 0)
        return 1;
    else if (res < 0)
        return (-1);
    else
        return 0;

}

int main()
{
    printf("Voici %d\n", strcmp("bonjour", "bonzour"));
    printf("Voici fausse %d\n\n", ft_strcmp("bonjour", "bonzour"));
    printf("Voici %d\n", strcmp("bonjour", "bonbour"));
    printf("Voici fausse %d\n\n", ft_strcmp("bonjour", "bonbour"));
    printf("Voici %d\n", strcmp("bonjour", "bonjour"));
    printf("Voici fausse %d\n\n", ft_strcmp("bonjour", "bonjour"));
    return 0;
}