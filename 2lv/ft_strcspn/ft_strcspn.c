#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (*s)
    {
        while (reject[i] && *s != reject[i])
            i++;
        if (reject[i] != '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}

int main()
{
    printf("Voici : %ld\n", strcspn("bonjour", "eqw"));
    printf("Voici : %ld\n", ft_strcspn("bonjour", "eqw"));

    return 0;

}