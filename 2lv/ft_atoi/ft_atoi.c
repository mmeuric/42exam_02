#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;
    int count = 0;

    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    while (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
        count++;
    }
    while (*str)
    {
        res = res * 10 + (*str - 48);
        str++;
    }
    if (count == 0 || count == 1)
        return (res * sign);
    else
        return 0;
}

int main(void)
{
    printf("Vraie %d\t et %d\t Vraie %d\t et %d\t", atoi("1234"), 
         atoi("-1234"), atoi("0"), atoi("-+--1234"));
    printf("\n\n");
    printf("Fausse %d\t et %d\t Fausse %d\t et %d\t", ft_atoi("1234"), 
        ft_atoi("-1234"), ft_atoi("0"), ft_atoi("-+--1234"));
    return 0;
}