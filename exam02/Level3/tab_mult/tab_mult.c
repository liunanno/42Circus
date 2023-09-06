#include <unistd.h>

void    ft_putnbr(int nb)
{
    char    c;

    if (nb > 0)
    {
        ft_putnbr(nb / 10);
        c = nb % 10 + '0';
        write(1, &c, 1);
    }
}

int ft_atoi(char *str)
{
    int i;
    int total;
    int nb;

    i = 1;
    total = str[0] - '0';
    while (str[i])
    {
        total *= 10;
        nb = str[i] - '0';
        total += nb;
        i++;
    }
    return (total);
}

void    tab_mult(char *str)
{
    int nb;
    int i;

    i = 1;
    nb = ft_atoi(str);
    while (i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(nb);
        write(1, " = ", 3);
        ft_putnbr(nb * i);
        write(1, "\n", 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        tab_mult(av[1]);
    else
        write(1, "\n", 1);
    return (0);
}