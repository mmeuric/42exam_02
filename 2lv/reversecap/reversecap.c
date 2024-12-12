#include <unistd.h>

void    ft_lowcase(char *str)
{
    int i = 0;

    while (str[i])
    {
    if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;
    i++;
    }
}

void    ft_revcap(char *str)
{
    int i = 0;

    ft_lowcase(str);
    while (str[i])
    {
        if (str[i + 1] == '\0' || str[i + 1] == ' ' || str[i + 1] == '\t')
            str[i] -= 32;
        write(1 , &str[i],1);
        i++;
    }

}

int main(int ac, char **av)
{
    int i = 1;
    if (ac > 1)
    {
        while (i < ac)
        {            
            ft_revcap(av[i]);
            write (1, "\n", 1);
            i++;
        }
    }
    else 
        write(1, "\n", 1);
    return 0;
}
