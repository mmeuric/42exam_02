#include <unistd.h>

void    ft_last(char *str)
{
    int i = 0;
    int j;
    while (str[i])
    {
        if (str[i] == ' ' && (str[i + 1] >= 33 && str[i + 1] <= 126))
            j = i + 1;
        i++;
    }
    while (str[j] >= 33 && str[j] <= 126)
    {
        write(1, &str[j],1);
        j++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ft_last(av[1]);
    }
    write( 1, "\n", 1);
    return 0;
}