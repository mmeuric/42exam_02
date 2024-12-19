#include <unistd.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
}

int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;

    if (*str == '-')
    {
        sign *= -1;
        str++;
    }
    while (*str)
    {
        res = (res * 10) + (*str - 48);
        str++;
    }
    return (res * sign);
}

void    ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    nb %= 10;
    nb += 48;
    write(1, &nb, 1);
}    

int main(int ac, char **av)
{
    int res = 0;
    if (ac == 3 && ft_atoi(av[1]) > 0 && ft_atoi(av[2]) > 0)
    {
        res = gcd(ft_atoi(av[1]), ft_atoi(av[2]));
        ft_putnbr(res);
    }
    write(1,"\n",1);
    return (0);
}