#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (*s)
    {
        while (accept[i] && *s != accept[i])
            i++;
        if (accept[i] == '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}

int main()
{
    printf("Voici : %ld\n", strspn("bonjour", "eqw"));
    printf("Voici : %ld\n", ft_strspn("bonjour", "eqw"));

    return 0;

}