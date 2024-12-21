#include <unistd.h>

void    ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    nb %= 10;
    nb += 48;
    write(1, &nb,1);
}

int main(int ac, char **av)
{
    (void)av;

    ft_putnbr(ac - 1);
    write(1,"\n",1); 
    return (0);
}